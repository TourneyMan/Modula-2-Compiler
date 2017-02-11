using System;
using System.Collections;		// ArrayList, HashTable, Stack

namespace Compiler
{
/******************* Stack Description *******************************************

    The procedure call needs a few words of explanation:

    Note STACK_START (set to 8) The first four bytes are used for EBP (to return).
    The next two store the IP register (to return).
    IP is pushed by CALL. The CALLEE pushes EBP. 

    Next are the parameters (the first parameter is pushed first,
    Last are the local variables, pushed onto the stack as they are encountered.
            
    Here is a hypothetical stack with two local variables and three parameters (e.g. Towers of Hanoi).
    All are assumed to be four byte integers (except for param 2 which is one byte.
    These conventions correspond roughly to those of Dandamudi, p. 142

        Note that the Intel stack decrements and that the "new" value of BP
            (the value used during statements within this procedure) is equal to the
            lowest address. Note that iMemory needed would be set to 21 after encountering
            all variables in this scope.

        param 1     ebp + 24
        param 2     ebp + 20
        param 3     ebp + 16
        local 1     ebp + 12
        local 2     ebp + 8
        EIP         ebp + 4
        EBP         ebp

        While in the scope of the procedure, the next available byte will be 21,
        so to reach local variables or parameters, 
        the emitter needs to look at bp + (PROC_mem_total - Var_offset + 4) 

        After parsing all parameters and local variables, AdjustMemoryOffset() will change "offset"
        to the actual offset (using this equation). It makes more sense to do
        this once at parse time than redo the math for every reference.

    This further requires the CALLER to subtract (or "push") iLocalVarSpaceNeeded from SP after 
    pushing the parameters onto the stack, but before the call. At the end of the PROC, 
    the CALLEE will need to pop BP and then "ret (PROC_offset - 4)" (that is, return that number) 
    to clean up the stack.

Consider a version of this stack that includes an array.

        the stack   pointer  Variable "offset"
                            in pAttr      
                            = memory needed
                            after this var 
                            is included

        param 1     bp + 32       8
        local 1     bp + 28      12
        loc array   bp + 8       32          array of 5 INTEGERS
        local 2     bp + 4       36
        IP          bp + 2      none
        BP          bp          none

Before we start executing PROC statments, we push everything onto the stack, then call
the PROC (which pushes IP onto the stack), then we "push BP" and finally "mov BP,SP". 
Now everything is just where we want it during PROC execution.
    
Note too that the stack grows downward. Tom wrote a test program ("C:\classes\cs380\Mod\test_stack.a")
    that illustrates this. Subtracting x from the stack pointer is equivalent to pushing
    x bytes onto the stack.
       
*********************************************************************************/

    /// <summary>
    /// Symbol constitutes each entry in the symbol table. It stores information needed by
    ///    the parser and emitter for each identifier (ID). ID's may be variables, constants,
    ///    or procedures.
    /// </summary>
    public class Symbol
    {
        /// <summary>
        /// This enumerated type defines the type of identifier/variable. 
        /// Note that TYPE_SIMPLE is a simple type like INTEGER or CARDINAL
        /// TYPE_TYPE_SIMPLE is the name of a derived type based on a simple type
        /// TYPE_ARRAY is the type of an array. The items in the array are identified by 
        ///       STORE_TYPE that follows
        /// TYPE_TYPE_ARRAY is the name of a derived array type (e.g. "listType")
        /// </summary>
        public enum SYMBOL_TYPE
        {
            /*0*/
            TYPE_NONE, TYPE_CONST, TYPE_TYPE_SIMPLE, TYPE_SIMPLE, TYPE_TYPE_ARRAY,
            /*5*/
            TYPE_ARRAY, TYPE_TYPE_STRING, TYPE_STRING, TYPE_PROC, TYPE_FUNCTION,
            /*-1*/
            TYPE_ERROR = -1
        };

        /// <summary>
        /// What kind of storage is needed for this symbol?
        /// </summary>
        public enum STORE_TYPE
        { /*0*/ STORE_NONE, TYPE_INT, TYPE_RL, TYPE_CD };

        /// <summary>
        /// VAL_PARM and REF_PARM are parameters (within the scope of a procedure)
        ///     LOCAL_VAR are local variables within a procedure or in main (stored on the stack)
        /// </summary>
        public enum PARM_TYPE
        { /*0*/ VAL_PARM, REF_PARM, LOCAL_VAR };

        // track the symbol type of this symbol
        public SYMBOL_TYPE symbolType;

        // track the store type of this symbol
        public STORE_TYPE storeType;

        // track the param type of this symbol
        public PARM_TYPE paramType;

        public int scopeNumber,     // scope of this symbol
                    constIntValue,  // value for a constant integer
                    memOffset,      // offset in bytes within current stack frame
                    lowerBound,     // array lower limit
                    upperBound;     // array upper limit

        // for procedures only, used to retain information about parameters used
        public ProcVarList paramVarList;

        /// <summary>
        /// Create an empty Symbol with scope retrieved from SymbolTable.
        /// </summary>
        public Symbol() { scopeNumber = SymbolTable.CUR_SCOPE; } // Symbol

        /// <summary>
        /// copy constructor
        /// </summary>
        /// <param name="sym"></param>
        public Symbol(Symbol sym)
        {
            symbolType = sym.symbolType;
            storeType = sym.storeType;
            paramType = sym.paramType;
            scopeNumber = sym.scopeNumber;
            constIntValue = sym.constIntValue;
            memOffset = sym.memOffset;
            lowerBound = sym.lowerBound;
            upperBound = sym.upperBound;
            paramVarList = sym.paramVarList;    //  Warning...shallow copy
        } // Symbol

        /// <summary>
        /// copy function
        /// </summary>
        /// <param name="sym"></param>
        public void Copy(Symbol sym)
        {
            symbolType = sym.symbolType;
            storeType = sym.storeType;
            paramType = sym.paramType;
            scopeNumber = sym.scopeNumber;
            constIntValue = sym.constIntValue;
            memOffset = sym.memOffset;
            lowerBound = sym.lowerBound;
            upperBound = sym.upperBound;
            paramVarList = sym.paramVarList;    //  Warning...shallow copy

        } // Copy

    } // Symbol class

    /// <summary>
    /// This handles one procedure completely. It stores the list
    ///    of variables (ArrayList of string), the local memory needed, 
    ///    and the parameter count for this one procedure.
    /// </summary>
    public class ProcVarList
    {
        string procName;

        /// <summary>
        /// block default constructor
        /// </summary>
        private ProcVarList() { } // ProcVarList

        /// <summary>
        /// only public constructor
        /// </summary>
        /// <param name="name"></param>
        public ProcVarList(string name)
        {
            procName = name;

        } // ProcVarList

        public string PROC_NAME
        { get { return procName; } } // PROC_NAME



    } // ProcVarList class

    /// <summary>
    /// The Symbol Table is a Singleton class that manages identifiers. 
    ///    
    ///    The table is maintained as a stack of Scope objects (defined below).
    /// </summary>
    class SymbolTable
    {
        // reference to the file manager
        static FileManager fm = FileManager.Instance;

        // keep track of the scope number
        static int currentScope;

        /// <summary>
        /// class to define and keep track of scopes for the scope stack
        /// </summary>
        class Scope
        {
            int scopeNumber;    // unique number for each scope
            Hashtable symbols;  // to store identifiers
            int currMemOffset;  // the offset at which the next stored value will be held

            /// <summary>
            /// Scope constructor
            ///     sets the scope number and creates a new hashtable to keep symbols for this scope
            /// </summary>
            public Scope()
            {
                scopeNumber = currentScope++;
                symbols = new Hashtable();
                currMemOffset = 8;

            } // Scope constructor

            /// <summary>
            /// get scope number
            /// </summary>
            public int SCOPE_NUMBER
            { get { return scopeNumber; } } // SCOPE_NUMBER

            /// <summary>
            /// get currMemOffset
            /// </summary>
            public int MEM_OFFSET
            { get { return currMemOffset; }
              set { currMemOffset = value; }
            } // SCOPE_NUMBER

            /// <summary>
            /// get symbols  hashtable
            /// </summary>
            public Hashtable SYMBOLS
            { get { return symbols; } } // SCOPE_NUMBER

        } // Scope

        static Stack scopeStack;        // stack for storing scopes

        // The single object instance for this class.
        private static SymbolTable stInstance;

        // To prevent access by more than one thread. This is the specific lock 
        //    belonging to the SymbolTable Class object.
        private static Object stLock = typeof(SymbolTable);

        // Instead of a constructor, we offer a static method to return the only
        //    instance.
        private SymbolTable() { } // private constructor so no one else can create one.

        /// <summary>
        /// Management for static instance of this class
        /// </summary>
        public static SymbolTable Instance
        {
            get
            {
                lock (stLock)
                {
                    // if this is the first request, initialize the one instance
                    if (stInstance == null)
                    {
                        stInstance = new SymbolTable();
                        stInstance.Reset(); // reset all variables
                    }

                    // in either case, return a reference to the only instance
                    return stInstance;
                }
            }

        } // SymbolTable Instance

        /// <summary>
        /// Reset the symbol table
        /// </summary>
        public void Reset()
        {
            currentScope = 0;           // first scope will be scope 0
            scopeStack = null;          // no scopes on the stack yet

        } // Reset

        /// <summary>
        /// Adds a symbol to the symbol table
        /// </summary>
        public void AddASymbol(String nameOfSymbol, Token.TOKENTYPE tokType)
        {
            Symbol symbolToAdd = new Symbol();
            if (tokType == Token.TOKENTYPE.INT_NUM)
            {
                symbolToAdd.symbolType = Symbol.SYMBOL_TYPE.TYPE_SIMPLE;
                symbolToAdd.paramType = Symbol.PARM_TYPE.LOCAL_VAR;
                symbolToAdd.storeType = Symbol.STORE_TYPE.TYPE_INT;
                symbolToAdd.memOffset = TOP_SCOPE.MEM_OFFSET;
                TOP_SCOPE.MEM_OFFSET += 4;
            }

            else if (tokType == Token.TOKENTYPE.ID)
            {
                symbolToAdd.symbolType = Symbol.SYMBOL_TYPE.TYPE_PROC;
                symbolToAdd.paramType = Symbol.PARM_TYPE.VAL_PARM;
                symbolToAdd.storeType = Symbol.STORE_TYPE.STORE_NONE;
                symbolToAdd.memOffset = 0;
            }

            //symbolToAdd.
            //Symbol symbolToAdd = new Symbol(tokType);
            TOP_SCOPE.SYMBOLS.Add(nameOfSymbol, symbolToAdd);
        } // AddASymbol

        /// <summary>
        /// Enters a new scope
        /// </summary>
        public void EnterNewScope(String name)
        {
            if (scopeStack == null)
            {
                scopeStack = new Stack();
            }
            scopeStack.Push(new Scope());
            AddASymbol(name, Token.TOKENTYPE.ID);
        } // EnterNewScope

        /// <summary>
        /// Populates the string to represent the symbol table
        /// </summary>
        public void DumpSymbolTable()
        {
            while (scopeStack.Count != 0) {
                Scope thisScope = (Scope)scopeStack.Pop();
                foreach (Symbol mySymbol in thisScope.SYMBOLS)
                {
                    fm.SYMBOL_LIST += "test";
                }
            }
            fm.SYMBOL_LIST += "dog";
        } // DumpSymbolTable

        /// <summary>
        /// get the top scope on the stack and return it
        /// </summary>
        private static Scope TOP_SCOPE
        {
            get
            {
                if (scopeStack == null || scopeStack.Count <= 0) return null;
                else return (Scope)scopeStack.Peek();
            }
        } // TOP_SCOPE

        /// <summary>
        /// get the scope number of the top scope on the scope stack
        /// </summary>
        public static int CUR_SCOPE
        {
            get
            {
                if (TOP_SCOPE == null) return -1;
                else return TOP_SCOPE.SCOPE_NUMBER;
            }
        } // CUR_SCOPE

    } // SymbolTable class

} // Compiler namespace