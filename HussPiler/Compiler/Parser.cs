using System;

namespace Compiler
{
    /// <summary>
    /// Parser is a singleton class that receives a list of tokens 
    /// and parses them according to Modula-2 grammar.
    /// </summary>
    class Parser
    {
        // singleton instances
        private FileManager fm = FileManager.Instance;
        private Lexer lexer = Lexer.Instance;
        private SymbolTable symTbl = SymbolTable.Instance;

        // The single object instance for this class.
        private static Parser pInstance;

        // To prevent access by more than one thread. This is the specific lock 
        //    belonging to the Parser Class object.
        private static Object pLock = typeof(Parser);

        // Instead of a constructor, we offer a static method to return the only
        //    instance.
        private Parser() { } // private constructor so no one else can create one.

        /// <summary>
        /// Management for static instance of this class
        /// </summary>
        public static Parser Instance
        {
            get
            {
                lock (pLock)
                {
                    // if this is the first request, initialize the one instance
                    if (pInstance == null)
                    {
                        pInstance = new Parser();
                        pInstance.Reset();
                    }

                    // in either case, return a reference to the only instance
                    return pInstance;
                }
            }

        } // Parser Instance

        /// <summary>
        /// Reset all the things that need to be reset in the parser and SymTable
        /// </summary>
        public void Reset()
        {
            symTbl.Reset();

        } // Reset

        /// <summary>
        /// stub function to test basic functions of our symbol table
        /// - create new symbols and scopes
        /// </summary>
        public void TestSymbolTable()
        {
            ///Test///
            Reset();
            symTbl.EnterNewScope("HussPiler_Main");
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.AddASymbol("var2", Symbol.SYMBOL_TYPE.TYPE_CONST, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.VAL_PARM);
            symTbl.AddASymbol("var3", Symbol.SYMBOL_TYPE.TYPE_CONST, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.VAL_PARM);
            symTbl.AddASymbol("var4", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.AddASymbol("var5", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.EnterNewScope("Proc1");
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.LeaveScope();
            symTbl.EnterNewScope("Proc2");
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);

            //PARM_TYPE is intentionally wrong -- should be fixed by RetrieveSymbolInnerScope
            symTbl.AddASymbol("var2", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.REF_PARM);
            symTbl.EnterNewScope("Proc3");

            //STORE_TYPE is intentionally wrong -- should be fixed by RetrieveSymbolCurrScope
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_CD, Symbol.PARM_TYPE.LOCAL_VAR);

            //Demonstrating that I can retrieve and modify symbols
            symTbl.RetrieveSymbolInnerScope("var2").paramType = Symbol.PARM_TYPE.LOCAL_VAR;
            symTbl.RetrieveSymbolCurrScope("var1").storeType = Symbol.STORE_TYPE.TYPE_INT;

            symTbl.LeaveScope();
            symTbl.LeaveScope();
            symTbl.LeaveScope();

            //Previous test when AddASymbol took a TokenType
            /*symTbl.EnterNewScope("procA");
            symTbl.AddASymbol("var1", Token.TOKENTYPE.INT_NUM);
            symTbl.AddASymbol("var2", Token.TOKENTYPE.INT_NUM);
            symTbl.AddASymbol("var3", Token.TOKENTYPE.INT_NUM);
            symTbl.EnterNewScope("procB");
            symTbl.AddASymbol("var4", Token.TOKENTYPE.INT_NUM);
            symTbl.AddASymbol("var5", Token.TOKENTYPE.INT_NUM);
            symTbl.LeaveScope();
            symTbl.AddASymbol("var6", Token.TOKENTYPE.INT_NUM);
            symTbl.EnterNewScope("procC");
            symTbl.AddASymbol("var7", Token.TOKENTYPE.INT_NUM);
            symTbl.DumpSymbolTable();*/
        } // TestSymbolTable

    } // Parser

} // Compiler namespace