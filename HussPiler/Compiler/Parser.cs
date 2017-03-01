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

            Match(Token.TOKENTYPE.ID);
            Match(Token.TOKENTYPE.SEMI_COLON);

            while (curTok.tokType != Token.TOKENTYPE.BEGIN) { Submodule(); }

            Match(Token.TOKENTYPE.BEGIN);

            while (curTok.tokType != Token.TOKENTYPE.END) { Submodule(); }

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
        /// Pre: Expecting a VAR submodule
        /// Reads in the next VAR submodule, setting needed variables
        /// </summary>
        private void VARSubmodule()
        {
            Match(Token.TOKENTYPE.VAR);

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
                    symTbl.AddASymbol(((Token)tokenStack.Pop()).lexName, Symbol.SYMBOL_TYPE.TYPE_SIMPLE, Symbol.STORE_TYPE.TYPE_INT, Symbol.PARM_TYPE.LOCAL_VAR);
                }
                Match(Token.TOKENTYPE.INTEGER);
            }

            //We only accept INTEGER vars for now
            else {
                throw new Exception("Parser - VARSubmodule: Invalid variable type");
            }
            Match(Token.TOKENTYPE.SEMI_COLON);
        } // VARSubmodule

        /// <summary>
        /// Pre: Expecting an ID submodule
        /// Reads in the next ID submodule
        /// </summary>
        private void IDSubmodule()
        {
            //Store info about our ID in question
            string nameOfId = curTok.lexName;
            Symbol.STORE_TYPE storeType = symTbl.RetrieveSymbolCurrScope(nameOfId).storeType;
            int idMemOffset = symTbl.RetrieveSymbolCurrScope(nameOfId).memOffset;

            Match(Token.TOKENTYPE.ID);

            //If we are assigning our id to something (not sure if there will be more options in the future)
            if (curTok.tokType == Token.TOKENTYPE.ASSIGN) {
                Match(Token.TOKENTYPE.ASSIGN);

                //If the ID corresponds to an integer variable, build the integer and assign the built int to the var
                if (storeType == Symbol.STORE_TYPE.TYPE_INT) {
                    BuildIntOnTopOfStack();
                    emitter.AssignTopOfStackToIntVar(idMemOffset);
                }
            }

            Match(Token.TOKENTYPE.SEMI_COLON);
        } // WRLNSubmodule

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
        /// WARNING: Currently assumes that your int will not involve anything but a single int in its formation
        /// Reads in the next Tokens until a int is formed.
        /// </summary>
        /// <returns>Returns the formed int</returns>
        private void BuildIntOnTopOfStack()
        {
            //If we only have a single number, just put it on the stack
            if (curTok.tokType == Token.TOKENTYPE.INT_NUM) {
                emitter.PutIntOnTopOfStack(Int32.Parse(curTok.lexName));
                Match(Token.TOKENTYPE.INT_NUM);
            }

            //If we only have a single variable, just put it on the stack
            if (curTok.tokType == Token.TOKENTYPE.ID)
            {
                emitter.PutIntVarOnTopOfStack(symTbl.RetrieveSymbolCurrScope(curTok.lexName).memOffset);
                Match(Token.TOKENTYPE.ID);
            }
        } // GetStringFromTokens

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