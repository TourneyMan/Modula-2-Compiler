using System;
using System.Collections;

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
        private Emitter emitter = Emitter.Instance;

        // Store the current token from the tokenizer.
        static Token curTok;
        private static Stack controlStructureStack = new Stack();
        private static Stack ifNumStack = new Stack();
        private static int ifNum = 0;
        private static Stack loopNumStack = new Stack();
        private static int loopNum = 0;
        private static int relNum = 0;
        private static int logNum = 0;
        Stack boolOpStack = new Stack();
        Stack procNames = new Stack();

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
            lexer.Reset();
            symTbl.Reset();
            emitter.Reset();
            curTok = null;

        } // Reset

        /// <summary>
        /// Match is used to validate that the current token is expected.
        /// PRE:  The current token has been loaded.
        /// POST: The current token is verified and the next one loaded. If errors are encountered,
        ///    an exception is thrown.
        /// </summary>
        void Match(Token.TOKENTYPE tokType)
        {
            // Have we loaded a token from the tokenizer?
            if (curTok == null)
            {
                throw new Exception("Parser - Match: c_tokCur is null.");
            }

            // Is the current token the one we expected?
            if (curTok.tokType == tokType)
            {
                // Is this the normal end of the source code file?
                if (tokType == Token.TOKENTYPE.EOF) { return; } // normal end of file

                // Otherwise load the next token from the tokenizer.
                curTok = lexer.GetNextToken(); // get the next token
            }
            else
            { // We have the wrong token; bail out gracefully
                string strMsg = string.Format("Expected {0}; found {1} ('{2}')at source line {3}",
                    tokType.ToString(), curTok.tokType.ToString(),
                    curTok.lexName, curTok.lineNumber);

                throw new Exception("Parser - Match: " + strMsg);
            }

        } // Match

        /// <summary>
        /// 
        /// </summary>
        public void Parse()
        {
            Reset();

            curTok = lexer.GetNextToken();

            symTbl.EnterProcScope(fm.MAIN_PROC);

            emitter.MainProcPreamble();

            Module();

            emitter.MainProcPostamble(symTbl.ExitProcScope());

            emitter.WriteAllFiles();

        } // Parse

        /// <summary>
        /// Reads through .mod file
        /// </summary>
        private void Module()
        {
            Match(Token.TOKENTYPE.MODULE);

            string moduleName = curTok.lexName;
            procNames.Push(moduleName);

            Match(Token.TOKENTYPE.ID);
            Match(Token.TOKENTYPE.SEMI_COLON);

            while (curTok.tokType != Token.TOKENTYPE.BEGIN) { Submodule(); }

            Match(Token.TOKENTYPE.BEGIN);

            int preControlCount = controlStructureStack.Count;
            while (curTok.tokType != Token.TOKENTYPE.END || controlStructureStack.Count > preControlCount) { Submodule(); }

            Match(Token.TOKENTYPE.END);

            // The next token should be the module name given at first.
            if (curTok.lexName != moduleName) throw new Exception("Module name not repeated at close of module.");

            Match(Token.TOKENTYPE.ID);
            Match(Token.TOKENTYPE.DOT);
            Match(Token.TOKENTYPE.EOF);

        } // Module

        /// <summary>
        /// Pre: Expecting a submodule
        /// Reads in the next submodule
        /// </summary>
        private void Submodule()
        {
            if (curTok.tokType == Token.TOKENTYPE.WRSTR) { WRSTRSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.WRLN) { WRLNSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.WRINT) { WRINTSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.VAR) { VARSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.ID) { IDSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.CONST) { CONSTSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.IF) { IFSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.ELSE) { ELSESubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.END) { ENDSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.LOOP) { LOOPSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.EXIT) { EXITSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.RDINT) { RDINTSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.CLS) { CLSSubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.TYPE) { TYPESubmodule(); }
            else if (curTok.tokType == Token.TOKENTYPE.PROCEDURE) { PROCEDURESubmodule(); }
        } // Submodule

        /// <summary>
        /// Pre: Expecting a WRSTR submodule
        /// Reads in the next WRSTR submodule
        /// </summary>
        private void WRSTRSubmodule()
        {
            Match(Token.TOKENTYPE.WRSTR);
            Match(Token.TOKENTYPE.LEFT_PAREN);
            string stringToDisplay = GetStringFromTokens();
            Match(Token.TOKENTYPE.RIGHT_PAREN);
            Match(Token.TOKENTYPE.SEMI_COLON);
            emitter.WRSTR(stringToDisplay);
        } // WRSTRSubmodule

        /// <summary>
        /// Pre: Expecting a WRINT submodule
        /// Reads in the next WRINT submodule
        /// </summary>
        private void WRINTSubmodule()
        {
            Match(Token.TOKENTYPE.WRINT);
            Match(Token.TOKENTYPE.LEFT_PAREN);
            BuildIntOnTopOfStack();
            Match(Token.TOKENTYPE.RIGHT_PAREN);
            Match(Token.TOKENTYPE.SEMI_COLON);
            emitter.WriteIntOnTopOfStack();
        } // WRINTSubmodule

        /// <summary>
        /// Pre: Expecting a WRLN submodule
        /// Reads in the next WRLN submodule
        /// </summary>
        private void WRLNSubmodule()
        {
            Match(Token.TOKENTYPE.WRLN);
            Match(Token.TOKENTYPE.SEMI_COLON);
            emitter.WRLN();
        } // WRLNSubmodule

        /// <summary>
        /// Pre: Expecting a CLS submodule
        /// Reads in the next CLS submodule
        /// </summary>
        private void CLSSubmodule()
        {
            Match(Token.TOKENTYPE.CLS);
            Match(Token.TOKENTYPE.SEMI_COLON);
            emitter.CLS();
        } // WRLNSubmodule

        /// <summary>
        /// Pre: Expecting a VAR submodule
        /// Reads in the next VAR submodule, setting needed variables
        /// </summary>
        private void VARSubmodule()
        {
            Match(Token.TOKENTYPE.VAR);

            while (curTok.tokType == Token.TOKENTYPE.ID)
            {
                //Read in list of Tokens that represent vars, hold them in the stack to be added to the symbol table later
                Stack tokenStack = new Stack();
                Boolean expectingComma = false;
                while (curTok.tokType != Token.TOKENTYPE.COLON) {
                    if (expectingComma) { Match(Token.TOKENTYPE.COMMA); expectingComma = false; }
                    else { tokenStack.Push(curTok); Match(Token.TOKENTYPE.ID); expectingComma = true; }
                }

                //We are finished adding Tokens to the stack
                Match(Token.TOKENTYPE.COLON);

                //Read in variable type and add to the symbol table accordingly
                if (curTok.tokType == Token.TOKENTYPE.INTEGER) {
                    while (tokenStack.Count != 0) {
                        string idName = ((Token)tokenStack.Pop()).lexName;
                        symTbl.AddASymbol(idName, Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);

                        //System.Diagnostics.Debug.WriteLine(symTbl.RetrieveSymbolCurrScope((string)procNames.Peek()) != null);
                        if (symTbl.RetrieveSymbolCurrScope((string)procNames.Peek()) != null)
                        {
                            symTbl.RetrieveSymbolCurrScope((string)procNames.Peek()).localVarMem += 4;
                        }
                    }
                    Match(Token.TOKENTYPE.INTEGER);
                }

                //Read in variable type and add to the symbol table accordingly
                else if (curTok.tokType == Token.TOKENTYPE.ID)
                {
                    //Get the base symbol to base these vars off of
                    Symbol sym = symTbl.RetrieveSymbolInnerScope(curTok.lexName);
                    if (sym == null) { throw new Exception("Parser - VARSubmodule: Invalid variable type"); }

                    //Make a var for each ID given, using sym as a template
                    while (tokenStack.Count != 0) {
                        if (sym.symbolType == Symbol.SYMBOL_TYPE.TYPE_TYPE_ARRAY) {
                            symTbl.AddASymbol(((Token)tokenStack.Pop()).lexName, Symbol.SYMBOL_TYPE.TYPE_ARRAY,
                                Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR, sym.lowerBound, sym.upperBound);
                        }
                    }
                    Match(Token.TOKENTYPE.ID);
                }

                else {
                    throw new Exception("Parser - VARSubmodule: Invalid variable type");
                }
                Match(Token.TOKENTYPE.SEMI_COLON);
            }

        } // VARSubmodule

        /// <summary>
        /// Pre: Expecting an ID submodule
        /// Reads in the next ID submodule
        /// </summary>
        private void IDSubmodule()
        {
            //Store info about our ID in question
            string nameOfId = curTok.lexName;
            Symbol sym = symTbl.RetrieveSymbolCurrScope(nameOfId);
            Match(Token.TOKENTYPE.ID);

            //Reading through array syntax and determining memoffset for specific array index
            if (sym.symbolType == Symbol.SYMBOL_TYPE.TYPE_ARRAY) {
                Match(Token.TOKENTYPE.LEFT_BRACK);

                //Put the index on top of the run-time stack
                BuildIntOnTopOfStack();

                //Prints out a run-time error if index on top of the stack is invalid
                //emitter.CheckValidIndex(sym.lowerBound, sym.upperBound, ifNum);
                //ifNum++;

                //Convert the index into an offset
                emitter.PutOffsetOnStack(sym.lowerBound, sym.memOffset);

                Match(Token.TOKENTYPE.RIGHT_BRACK);
                Match(Token.TOKENTYPE.ASSIGN);
                BuildIntOnTopOfStack();

                if (sym.paramType == Symbol.PARM_TYPE.REF_PARM) { emitter.AssignTopOfStackIntToRefAtMemOnStack(SymbolTable.MEM_OFFSET_TOP_SCOPE); }
                else { emitter.AssignTopOfStackIntToMemOnStack(); }
            }

            //For calling Procedures
            else if (sym.symbolType == Symbol.SYMBOL_TYPE.TYPE_PROC)
            {
                //Make room for local variables
                System.Diagnostics.Debug.WriteLine(sym.localVarMem);
                for (int i = 0; i < sym.localVarMem / 4; i++)
                {
                    emitter.PushZero();
                }

                //Grab all the parameters
                Match(Token.TOKENTYPE.LEFT_PAREN);

                Stack tempIsRef = new Stack();
                while (curTok.tokType != Token.TOKENTYPE.RIGHT_PAREN)
                {
                    tempIsRef.Push(symTbl.RetrieveSymbolCurrScope(nameOfId).isRef.Pop());

                    if ((bool) tempIsRef.Peek()) {

                        Symbol referredSymbol = symTbl.RetrieveSymbolCurrScope(curTok.lexName);

                        //For passing in integers by reference
                        if (referredSymbol.symbolType == Symbol.SYMBOL_TYPE.TYPE_SIMPLE)
                        {
                            emitter.PutIntOnTopOfStack(symTbl.RetrieveSymbolCurrScope(curTok.lexName).memOffset);
                        }

                        //For passing in arrays
                        else
                        {
                            for (int i = referredSymbol.upperBound - referredSymbol.lowerBound; i >= 0; i--)
                            {
                                emitter.PutIntOnTopOfStack(symTbl.RetrieveSymbolCurrScope(curTok.lexName).memOffset + (4 * i));
                            }
                        }

                        Match(Token.TOKENTYPE.ID);
                    }

                    else { BuildIntOnTopOfStack(); }    

                    if (curTok.tokType != Token.TOKENTYPE.RIGHT_PAREN)
                    {
                        Match(Token.TOKENTYPE.COMMA);
                    }
                }

                while (tempIsRef.Count > 0) { symTbl.RetrieveSymbolCurrScope(nameOfId).isRef.Push(tempIsRef.Pop()); }
                Match(Token.TOKENTYPE.RIGHT_PAREN);
                emitter.CallProc(nameOfId);
            }

            //For assignments
            //If the ID corresponds to an integer variable, build the integer and assign the built int to the var
            else
            {
                Match(Token.TOKENTYPE.ASSIGN);
                BuildIntOnTopOfStack();

                if (sym.paramType == Symbol.PARM_TYPE.REF_PARM)
                    emitter.AssignTopOfStackToReferredVar(sym.memOffset, SymbolTable.MEM_OFFSET_TOP_SCOPE);

                else
                    emitter.AssignTopOfStackToIntVar(sym.memOffset);
            }

            Match(Token.TOKENTYPE.SEMI_COLON);
        } // IDSubmodule

        /// <summary>
        /// Pre: Expecting a CONST submodule
        /// Reads in the next CONST submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void CONSTSubmodule()
        {
            Match(Token.TOKENTYPE.CONST);

            while (curTok.tokType == Token.TOKENTYPE.ID) {
                string symbolName = curTok.lexName;
                symTbl.AddASymbol(symbolName, Symbol.SYMBOL_TYPE.TYPE_CONST, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.VAL_PARM);
                Match(Token.TOKENTYPE.ID);
                Match(Token.TOKENTYPE.EQUAL);
                symTbl.RetrieveSymbolCurrScope(symbolName).constIntValue = Convert.ToInt32(curTok.lexName);
                Match(Token.TOKENTYPE.INT_NUM);
                Match(Token.TOKENTYPE.SEMI_COLON);

            }
        } // CONSTSubmodule

        /// <summary>
        /// Pre: Expecting a IF submodule
        /// Reads in the next IF submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void IFSubmodule()
        {
            //To keep track of our if and what labels it should have in the asm code
            controlStructureStack.Push("if");
            ifNumStack.Push(ifNum);
            ifNum++;

            //Match the structure and build the boolean
            Match(Token.TOKENTYPE.IF);
            BuildBooleanOnTopOfStack();
            Match(Token.TOKENTYPE.THEN);
            emitter.IfStatement((int)ifNumStack.Peek());

            //To keep track of what control level this if statement is on
            int baseControlStackCount = controlStructureStack.Count;

            //Generate asm code until we hit the else or end or the if statement
            while ((curTok.tokType != Token.TOKENTYPE.ELSE || controlStructureStack.Count > baseControlStackCount) &&
             (curTok.tokType != Token.TOKENTYPE.END || controlStructureStack.Count > baseControlStackCount)) { Submodule(); }

            //Create an else label even if there is no else in the modulo-2 code
            emitter.ElseStatement((int)ifNumStack.Peek());
        } // IFSubmodule

        /// <summary>
        /// Pre: Expecting an ELSE submodule
        /// Reads in the next ELSE submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void ELSESubmodule()
        {
            //Else label has already been created in the 'if' submodule
            Match(Token.TOKENTYPE.ELSE);
        } // ELSESubmodule

        /// <summary>
        /// Pre: Expecting an END submodule
        /// Reads in the next END submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void ENDSubmodule()
        {
            Match(Token.TOKENTYPE.END);

            //Determine what kind of control structure we are ending
            string controlStructure = (string) controlStructureStack.Pop();

            //Output the appropriate asm code to end that structure
            if (controlStructure.Equals("if")) { emitter.EndIf((int)ifNumStack.Pop()); }
            else if (controlStructure.Equals("loop")) { emitter.LoopEnd((int)loopNumStack.Pop()); }

            Match(Token.TOKENTYPE.SEMI_COLON);
        } // ENDSubmodule

        /// <summary>
        /// Pre: Expecting a LOOP submodule
        /// Reads in the next LOOP submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void LOOPSubmodule()
        {
            //To keep track of which loop number this loop is for
            controlStructureStack.Push("loop");
            loopNumStack.Push(loopNum);
            loopNum++;

            //Asm code to make label for beginning of loop
            emitter.LoopBegin((int)loopNumStack.Peek());
            Match(Token.TOKENTYPE.LOOP);
        } // LOOPSubmodule

        /// <summary>
        /// Pre: Expecting an EXIT submodule
        /// Reads in the next EXIT submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void EXITSubmodule() {
            //Asm code to jump to end of loop
            emitter.ExitLoop((int)loopNumStack.Peek());
            Match(Token.TOKENTYPE.EXIT);
            Match(Token.TOKENTYPE.SEMI_COLON);
        } // EXITSubmodule

        /// <summary>
        /// Pre: Expecting an RDINT submodule
        /// Reads in the next RDINT submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void RDINTSubmodule()
        {
            //Asm code to read in an int
            Match(Token.TOKENTYPE.RDINT);
            Match(Token.TOKENTYPE.LEFT_PAREN);
            emitter.ReadInt();
            Match(Token.TOKENTYPE.RIGHT_PAREN);
        } // RDINTSubmodule

        /// <summary>
        /// Pre: Expecting an TYPE submodule
        /// Reads in the next TYPE submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void TYPESubmodule()
        {
            try {
                Match(Token.TOKENTYPE.TYPE);

                while (curTok.tokType == Token.TOKENTYPE.ID)
                {
                    //Get the name of the new type
                    string typeName = curTok.lexName;
                    Match(Token.TOKENTYPE.ID);
                    Match(Token.TOKENTYPE.EQUAL);

                    if (curTok.tokType == Token.TOKENTYPE.ARRAY) {
                        Match(Token.TOKENTYPE.ARRAY);

                        //Store the start and end indices of this type of array
                        Match(Token.TOKENTYPE.LEFT_BRACK);
                        int arrayStart = Convert.ToInt32(curTok.lexName);
                        Match(Token.TOKENTYPE.INT_NUM);
                        Match(Token.TOKENTYPE.DOT_DOT);
                        int arrayEnd = Convert.ToInt32(curTok.lexName);
                        Match(Token.TOKENTYPE.INT_NUM);
                        Match(Token.TOKENTYPE.RIGHT_BRACK);
                        Match(Token.TOKENTYPE.OF);
                        Match(Token.TOKENTYPE.INTEGER);
                        Match(Token.TOKENTYPE.SEMI_COLON);

                        //Create a symbol used to define this type of variable later on
                        symTbl.AddASymbol(typeName, Symbol.SYMBOL_TYPE.TYPE_TYPE_ARRAY, Symbol.STORE_TYPE.STORE_NONE, Symbol.PARM_TYPE.VAL_PARM);
                        symTbl.RetrieveSymbolCurrScope(typeName).lowerBound = arrayStart;
                        symTbl.RetrieveSymbolCurrScope(typeName).upperBound = arrayEnd;
                    }
                }
            }

            catch (Exception e) { throw new Exception("Parser - TYPESubmodule: Invalid type definition"); }
        } // TYPESubmodule

        /// <summary>
        /// Pre: Expecting an PROCEDURE submodule
        /// Reads in the next PROCEDURE submodule
        /// </summary>
        /// ******************INCOMPLETE***************** ///
        private void PROCEDURESubmodule()
        {
            //Symbol procSymbol = new Symbol();
            //procSymbol.symbolType = Symbol.SYMBOL_TYPE.TYPE_PROC;
            string procName;

            Match(Token.TOKENTYPE.PROCEDURE);
            procName = curTok.lexName;

            symTbl.EnterProcScope(procName);
            emitter.ProcPreamble(procName);
            procNames.Push(procName);

            Match(Token.TOKENTYPE.ID);
            Match(Token.TOKENTYPE.LEFT_PAREN);

            Stack isRef = new Stack();
            Stack parameterNames = new Stack();

            //Reading in parameters
            if (curTok.tokType != Token.TOKENTYPE.RIGHT_PAREN)
            {
                while (curTok.tokType != Token.TOKENTYPE.COLON)
                {
                    if (curTok.tokType == Token.TOKENTYPE.COMMA) { Match(Token.TOKENTYPE.COMMA); }

                    if (curTok.tokType == Token.TOKENTYPE.VAR) {
                        Match(Token.TOKENTYPE.VAR);
                        isRef.Push(true);
                        symTbl.RetrieveSymbolCurrScope(procName).isRef.Push(true);
                    }
                    else { isRef.Push(false); symTbl.RetrieveSymbolCurrScope(procName).isRef.Push(false); }

                    parameterNames.Push(curTok.lexName);
                    Match(Token.TOKENTYPE.ID);
                }
                Match(Token.TOKENTYPE.COLON);

                //Integer is the only option I know of at the moment
                if (curTok.tokType == Token.TOKENTYPE.INTEGER)
                {
                    Match(Token.TOKENTYPE.INTEGER);

                    Stack tempIsRef = new Stack();
                    while (parameterNames.Count > 0)
                    {
                        string nextParam = (string)parameterNames.Pop();

                        //Adding the parameters to this scope's symbol table
                        tempIsRef.Push(isRef.Pop());
                        if ((bool)tempIsRef.Peek()) { symTbl.AddASymbol(nextParam, Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.REF_PARM); }
                        else { symTbl.AddASymbol(nextParam, Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.VAL_PARM); }
                    }
                    while (tempIsRef.Count > 0) { isRef.Push(tempIsRef.Pop()); }
                }

                //For arrays
                else
                {
                    Symbol arrayType = symTbl.RetrieveSymbolInnerScope(curTok.lexName);
                    Match(Token.TOKENTYPE.ID);

                    while (parameterNames.Count > 0)
                    {
                        string nextParam = (string)parameterNames.Pop();
                        symTbl.AddASymbol(nextParam, Symbol.SYMBOL_TYPE.TYPE_ARRAY, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.REF_PARM);
                        Symbol paramArray = symTbl.RetrieveSymbolCurrScope(nextParam);
                        paramArray.lowerBound = arrayType.lowerBound;
                        paramArray.upperBound = arrayType.upperBound;
                        SymbolTable.MEM_OFFSET_TOP_SCOPE += ((paramArray.upperBound - paramArray.lowerBound + 1) * 4);
                    }
                }
            }

            Match(Token.TOKENTYPE.RIGHT_PAREN);
            Match(Token.TOKENTYPE.SEMI_COLON);
            //End of reading in parameters

            while (curTok.tokType != Token.TOKENTYPE.BEGIN) { Submodule(); }
            Match(Token.TOKENTYPE.BEGIN);

            int preControlCount = controlStructureStack.Count;
            while (curTok.tokType != Token.TOKENTYPE.END || controlStructureStack.Count > preControlCount) { Submodule(); }

            Match(Token.TOKENTYPE.END);

            //procSymbol.paramVarList.MEM_USED = 0; //(symTbl.TOP_SCOPE.MEM_OFFSET - 8) + (procSymbol.paramVarList.PARAM_COUNT * 4);
            int locVarMem = symTbl.RetrieveSymbolCurrScope(procName).localVarMem;
            System.Diagnostics.Debug.WriteLine(locVarMem);
            int memOffset = symTbl.RetrieveSymbolCurrScope(procName).memOffset;
            emitter.ProcPostamble(procName, symTbl.ExitProcScope());
            symTbl.RetrieveSymbolCurrScope(procName).localVarMem = locVarMem;
            //symTbl.RetrieveSymbolCurrScope(procName).localVarMem = memOffset;
            symTbl.RetrieveSymbolCurrScope(procName).isRef = isRef;

            Stack tempStack = new Stack();

            procNames.Pop();

            if (curTok.lexName != procName) throw new Exception("Procedure name not repeated at close of procedure.");
            Match(Token.TOKENTYPE.ID);

            Match(Token.TOKENTYPE.SEMI_COLON);
        } // PROCEDURESubmodule

        /// <summary>
        /// Pre: Expecting an boolean to form from the upcoming tokens
        /// Reads in the next Tokens until a boolean is formed.
        /// </summary>
        private void BuildBooleanOnTopOfStack() {
            boolOpStack = new Stack();

            while (curTok.tokType != Token.TOKENTYPE.THEN)
            {
                //If operator, add it to the stack
                if (curTok.tokType == Token.TOKENTYPE.NOT) { boolOpStack.Push('!'); Match(Token.TOKENTYPE.NOT);  }
                else if (curTok.tokType == Token.TOKENTYPE.LEFT_PAREN) { boolOpStack.Push('('); Match(Token.TOKENTYPE.LEFT_PAREN); }
                else if (curTok.tokType == Token.TOKENTYPE.AND) { boolOpStack.Push('&'); Match(Token.TOKENTYPE.AND); }

                //Evaluate as we go... if it's another or, we can evaluate the other one that's now ready
                else if (curTok.tokType == Token.TOKENTYPE.OR) {
                    if (boolOpStack.Count > 0 && (char)boolOpStack.Peek() == '|') { emitter.NotOperator(logNum); logNum++; }
                    else { boolOpStack.Push('|'); }
                    Match(Token.TOKENTYPE.OR);
                }

                else {
                    BuildRelationalBoolean();

                    //Do all operations we are now ready to do
                    while ((boolOpStack.Count > 0 && ((char)boolOpStack.Peek() == '!' || (char)boolOpStack.Peek() == '&'))
                        || (curTok.tokType == Token.TOKENTYPE.RIGHT_PAREN))
                    {
                        if (boolOpStack.Count > 0 && (char)boolOpStack.Peek() == '!') { boolOpStack.Pop(); emitter.NotOperator(logNum); logNum++; }
                        else if (boolOpStack.Count > 0 && (char)boolOpStack.Peek() == '&') { boolOpStack.Pop(); emitter.AndOperator(logNum); logNum++; }

                        //Get rid of excess Parentheses
                        else
                        {
                            Match(Token.TOKENTYPE.RIGHT_PAREN);
                            if ((char)boolOpStack.Pop() != '(') { throw new Exception("Parser - Match: Inappropriate use of parentheses"); }
                        }
                    }

                }
            }

            //Do Operations still on stack
            while (boolOpStack.Count > 0) {
                char nextChar = (char) boolOpStack.Pop();
                if (nextChar == '!') { emitter.NotOperator(logNum); logNum++; }
                else if (nextChar == '|') { emitter.OrOperator(logNum); logNum++; }
                else if (nextChar == '&') { emitter.AndOperator(logNum); logNum++; }
            }
        } // BuildBooleanOnTopOfStack

        /// <summary>
        /// Pre: Expecting a relational boolean to form from the upcoming tokens
        /// Reads in the next Tokens until a boolean is formed.
        /// </summary>
        private void BuildRelationalBoolean() {

            //Taking care of potential parentheses
            int relBoolLeftParenCount = 0;
            while (curTok.tokType == Token.TOKENTYPE.LEFT_PAREN) { Match(Token.TOKENTYPE.LEFT_PAREN); relBoolLeftParenCount++; }

            BuildIntOnTopOfStack();

            //Could be a mis-appropriated parenthesis
            while (curTok.tokType == Token.TOKENTYPE.RIGHT_PAREN) {
                if (relBoolLeftParenCount == 0 && (char)boolOpStack.Peek() == '(') { boolOpStack.Pop(); Match(Token.TOKENTYPE.RIGHT_PAREN); }
            }

            Token.TOKENTYPE relType = curTok.tokType;
            Match(relType);
            BuildIntOnTopOfStack();

            while (relBoolLeftParenCount != 0) { Match(Token.TOKENTYPE.RIGHT_PAREN);  relBoolLeftParenCount--; }

            //Make comparison
            if (relType == Token.TOKENTYPE.EQUAL) { emitter.EqualsTopTwoInts(relNum); }
            else if (relType == Token.TOKENTYPE.NOT_EQ) { emitter.NotEqualsTopTwoInts(relNum); }
            else if (relType == Token.TOKENTYPE.GRTR_THAN) { emitter.GreaterTopTwoInts(relNum); }
            else if (relType == Token.TOKENTYPE.GRTR_THAN_EQ) { emitter.GreaterEqTopTwoInts(relNum); }
            else if (relType == Token.TOKENTYPE.LESS_THAN) { emitter.LessTopTwoInts(relNum); }
            else if (relType == Token.TOKENTYPE.LESS_THAN_EQ) { emitter.LessEqTopTwoInts(relNum); }

            relNum++;
        } // BuildRelationalBoolean

        /// <summary>
        /// Pre: Expecting a String to form from the upcoming tokens
        /// WARNING: Currently assumes that your string will not be a concatenation of multiple strings
        /// Reads in the next Tokens until a String is formed.
        /// </summary>
        /// <returns>Returns the formed string</returns>
        private string GetStringFromTokens()
        {
            string stringToReturn = curTok.lexName;
            Match(Token.TOKENTYPE.STRING);
            return stringToReturn;

        } // GetStringFromTokens

        /// <summary>
        /// Pre: Expecting an int to form from the upcoming tokens
        /// Reads in the next Tokens until a int is formed.
        /// </summary>
        private void BuildIntOnTopOfStack() {
            try {
                int expectedEndParen = 0;
                int intsOnRunStack = 0;
                Stack operationStack = new Stack();

                //All expressions start with an integer of some shape or form
                BuildIntegerPortion(ref expectedEndParen, ref intsOnRunStack, ref operationStack);

                //While we have a valid operation
                while (DoesBuildIntContinue(expectedEndParen)) {
                    BuildOperatorPortion(ref expectedEndParen, ref intsOnRunStack, ref operationStack);
                    BuildIntegerPortion(ref expectedEndParen, ref intsOnRunStack, ref operationStack);
                }

                //Complete remaining operations
                while (operationStack.Count != 0) { DoIntOperation((char)operationStack.Pop()); }

            }

            catch (Exception e) { throw new Exception("Parser - BuildIntOnTopOfStack: Could not read in proper integer expression"); }
        } // GetStringFromTokens

        /// <summary>
        /// Builds the portion of an integer expression that does not involve operator Tokens
        /// </summary>
        private void BuildIntegerPortion(ref int expectedEndParen, ref int intsOnRunStack, ref Stack operationStack) {

            //Assume we won't negatize our result
            bool negatizeNextInt = false;

            //First, search for potential left parentheses and add them on if they are there
            while (curTok.tokType == Token.TOKENTYPE.LEFT_PAREN) {
                operationStack.Push('(');
                Match(Token.TOKENTYPE.LEFT_PAREN);
                expectedEndParen++;
            }

            //Integers can lead with a plus or minus sign -- we need to negaitize when we have a leading negative
            if (curTok.tokType == Token.TOKENTYPE.PLUS || curTok.tokType == Token.TOKENTYPE.MINUS) {
                if (curTok.tokType == Token.TOKENTYPE.MINUS) { negatizeNextInt = true; }
                Match(curTok.tokType);
            }

            //Next we expect some kind integer itself
            if (curTok.tokType == Token.TOKENTYPE.INT_NUM || curTok.tokType == Token.TOKENTYPE.ID || curTok.tokType == Token.TOKENTYPE.RDINT) {
                if (curTok.tokType == Token.TOKENTYPE.INT_NUM) {
                    emitter.PutIntOnTopOfStack(Int32.Parse(curTok.lexName));
                    Match(Token.TOKENTYPE.INT_NUM);
                }
                
                //The int is to be read in
                else if (curTok.tokType == Token.TOKENTYPE.RDINT) { RDINTSubmodule(); }

                //We have an ID we recognize
                else if (symTbl.RetrieveSymbolInnerScope(curTok.lexName) != null) {
                    Symbol sym = symTbl.RetrieveSymbolInnerScope(curTok.lexName);

                    //We have a constant
                    if (sym.symbolType == Symbol.SYMBOL_TYPE.TYPE_CONST) {
                        emitter.PutIntOnTopOfStack(symTbl.RetrieveSymbolInnerScope(curTok.lexName).constIntValue);
                        Match(Token.TOKENTYPE.ID);
                    }
                    
                    //We have an array
                    else if (sym.symbolType == Symbol.SYMBOL_TYPE.TYPE_ARRAY)
                    {
                        Match(Token.TOKENTYPE.ID);
                        Match(Token.TOKENTYPE.LEFT_BRACK);

                        //Put the index on top of the run-time stack
                        BuildIntOnTopOfStack();

                        //Prints out a run-time error if index on top of the stack is invalid
                        //emitter.CheckValidIndex(sym.lowerBound, sym.upperBound, ifNum);
                        //ifNum++;

                        //Convert the index into an offset
                        emitter.PutOffsetOnStack(sym.lowerBound, sym.memOffset);

                        if (sym.paramType == Symbol.PARM_TYPE.REF_PARM) { emitter.PutIntOnStackFromMemOfRefOnStack(SymbolTable.MEM_OFFSET_TOP_SCOPE); }
                        else { emitter.PutIntOnStackFromMemOnStack(); }   

                        Match(Token.TOKENTYPE.RIGHT_BRACK);
                    }

                    //We have a variable
                    else {
                        //If this variable is actually a reference to other memory
                        if (sym.paramType == Symbol.PARM_TYPE.REF_PARM) { emitter.PutReferredVarOnStack(sym.memOffset, SymbolTable.MEM_OFFSET_TOP_SCOPE); }


                        //Regular variable
                        else { emitter.PutIntVarOnTopOfStack(sym.memOffset); }

                        Match(Token.TOKENTYPE.ID);
                    }
                }

                //ID not recognized
                else { throw new Exception("Error - Variable used, but not declared"); }

                if (negatizeNextInt) { emitter.NegatizeTopInt(); }
                intsOnRunStack++;

                //If we added a *, /, or % recently to operations, take care of that immediately 
                if (intsOnRunStack > 1 && ((char)operationStack.Peek() == '*' || (char)operationStack.Peek() == '/' || (char)operationStack.Peek() == '%')) {
                    DoIntOperation((char)operationStack.Pop());
                    intsOnRunStack--;
                }
            }

            else { throw new Exception("Error - Invalid expression"); }

            //Allow for right parentheses here
            while (curTok.tokType == Token.TOKENTYPE.RIGHT_PAREN) {
                if (DoesBuildIntContinue(expectedEndParen))
                {
                    if (expectedEndParen > 0)
                    {
                        while ((char)operationStack.Peek() != '(') { DoIntOperation((char)operationStack.Pop()); }
                        operationStack.Pop();
                        expectedEndParen--;
                        Match(Token.TOKENTYPE.RIGHT_PAREN);
                    }
                    else { throw new Exception("Error - Mismatching right parenthesis in integer expression"); }
                }
                //else if (boolOpStack.Count > 0 && (char)boolOpStack.Peek() == '(') { boolOpStack.Pop(); } //Good for popping off left parens
                else { break; }
            }
        }

        /// <summary>
        /// Builds the portion of an integer expression that involves reading in operator Tokens
        /// </summary>
        private void BuildOperatorPortion(ref int expectedEndParen, ref int intsOnRunStack, ref Stack operationStack) {

            //If we have an operation, push it on operation stack
            if (curTok.tokType == Token.TOKENTYPE.PLUS || curTok.tokType == Token.TOKENTYPE.MINUS || curTok.tokType == Token.TOKENTYPE.MULT ||
             curTok.tokType == Token.TOKENTYPE.DIV || curTok.tokType == Token.TOKENTYPE.MOD) {

                if (curTok.tokType == Token.TOKENTYPE.PLUS || curTok.tokType == Token.TOKENTYPE.MINUS) {
                    while (operationStack.Count != 0 && (char)operationStack.Peek() != '(') {
                        DoIntOperation((char)operationStack.Pop());
                        intsOnRunStack--;
                    }
                }

                if (curTok.tokType == Token.TOKENTYPE.PLUS) { operationStack.Push('+'); }
                else if (curTok.tokType == Token.TOKENTYPE.MINUS) { operationStack.Push('-'); }
                else if (curTok.tokType == Token.TOKENTYPE.MULT) { operationStack.Push('*'); }
                else if (curTok.tokType == Token.TOKENTYPE.DIV) { operationStack.Push('/'); }
                else if (curTok.tokType == Token.TOKENTYPE.MOD) { operationStack.Push('%'); }

                Match(curTok.tokType);
            }

            else { throw new Exception("Error - Expected operator"); }
        }

        /// <summary>
        /// Determines whether or not an int expression continues
        /// </summary>
        /// <returns>Returns the formed int</returns>
        private bool DoesBuildIntContinue(int expectedEndParen) {
            return curTok.tokType == Token.TOKENTYPE.INT_NUM || curTok.tokType == Token.TOKENTYPE.ID ||
                       curTok.tokType == Token.TOKENTYPE.PLUS || curTok.tokType == Token.TOKENTYPE.MULT ||
                       curTok.tokType == Token.TOKENTYPE.MINUS || curTok.tokType == Token.TOKENTYPE.DIV ||
                       curTok.tokType == Token.TOKENTYPE.MOD || curTok.tokType == Token.TOKENTYPE.LEFT_PAREN ||
                       (curTok.tokType == Token.TOKENTYPE.RIGHT_PAREN && expectedEndParen > 0);
        } //DoesBuildIntContinue

        /// <summary>
        /// Performs the operation indicated by the passed-in char to the top 2 ints on the run-time stack
        /// </summary>
        /// <returns>Returns the formed int</returns>
        private void DoIntOperation(char curOp)
        {
            if (curOp == '+') { emitter.AddTopTwoInts(); }
            else if (curOp == '-') { emitter.SubTopTwoInts(); }
            else if (curOp == '*') { emitter.MultTopTwoInts(); }
            else if (curOp == '/') { emitter.DivTopTwoInts(); }
            else if (curOp == '%') { emitter.ModTopTwoInts(); }
            else { throw new Exception("Parser - DoIntOperation: Given char did not correspond to valid operation"); }
        } //DoIntOperation

        /// <summary>
        /// stub function to test basic functions of our symbol table
        /// - create new symbols and scopes
        /// </summary>
        public void TestSymbolTable()
        {
            ///Test///
            Reset();
            symTbl.EnterProcScope("HussPiler_Main");
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.AddASymbol("var2", Symbol.SYMBOL_TYPE.TYPE_CONST, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.VAL_PARM);
            symTbl.AddASymbol("var3", Symbol.SYMBOL_TYPE.TYPE_CONST, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.VAL_PARM);
            symTbl.AddASymbol("var4", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.AddASymbol("var5", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.EnterProcScope("Proc1");
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
            symTbl.ExitProcScope();
            symTbl.EnterProcScope("Proc2");
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);

            //PARM_TYPE is intentionally wrong -- should be fixed by RetrieveSymbolInnerScope
            symTbl.AddASymbol("var2", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.REF_PARM);
            symTbl.EnterProcScope("Proc3");

            //STORE_TYPE is intentionally wrong -- should be fixed by RetrieveSymbolCurrScope
            symTbl.AddASymbol("var1", Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_CD, Symbol.PARM_TYPE.LOCAL_VAR);

            //Demonstrating that I can retrieve and modify symbols
            symTbl.RetrieveSymbolInnerScope("var2").paramType = Symbol.PARM_TYPE.LOCAL_VAR;
            symTbl.RetrieveSymbolCurrScope("var1").storeType = Symbol.STORE_TYPE.TYPE_INT;

            symTbl.ExitProcScope();
            symTbl.ExitProcScope();
            symTbl.ExitProcScope();

            //Previous test when AddASymbol took a TokenType
        } // TestSymbolTable

    } // Parser

} // Compiler namespace