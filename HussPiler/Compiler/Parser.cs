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

            while (curTok.tokType != Token.TOKENTYPE.END || controlStructureStack.Count > 0) { Submodule(); }

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
        /// Pre: Expecting an boolean to form from the upcoming tokens
        /// Reads in the next Tokens until a boolean is formed.
        /// </summary>
        private void BuildBooleanOnTopOfStack() {
            BuildRelationalBoolean();
        } // BuildBooleanOnTopOfStack

        /// <summary>
        /// Pre: Expecting a relational boolean to form from the upcoming tokens
        /// Reads in the next Tokens until a boolean is formed.
        /// </summary>
        private void BuildRelationalBoolean()
        {
            
            BuildIntOnTopOfStack();
            Token.TOKENTYPE relType = curTok.tokType;
            Match(relType);
            BuildIntOnTopOfStack();

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
            if (curTok.tokType == Token.TOKENTYPE.INT_NUM || curTok.tokType == Token.TOKENTYPE.ID) {
                if (curTok.tokType == Token.TOKENTYPE.INT_NUM) {
                    emitter.PutIntOnTopOfStack(Int32.Parse(curTok.lexName));
                    Match(Token.TOKENTYPE.INT_NUM);
                }

                //We have an ID we recognize
                else if (symTbl.RetrieveSymbolInnerScope(curTok.lexName) != null) {

                    //We have a constant
                    if (symTbl.RetrieveSymbolInnerScope(curTok.lexName).symbolType == Symbol.SYMBOL_TYPE.TYPE_CONST) {
                        emitter.PutIntOnTopOfStack(symTbl.RetrieveSymbolInnerScope(curTok.lexName).constIntValue);
                    }

                    //We have a variable
                    else { emitter.PutIntVarOnTopOfStack(symTbl.RetrieveSymbolInnerScope(curTok.lexName).memOffset); }
                    Match(Token.TOKENTYPE.ID);
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
            while (curTok.tokType == Token.TOKENTYPE.RIGHT_PAREN && DoesBuildIntContinue(expectedEndParen)) {
                if (expectedEndParen > 0) {
                    while ((char)operationStack.Peek() != '(') { DoIntOperation((char)operationStack.Pop()); }
                    operationStack.Pop();
                    expectedEndParen--;
                    Match(Token.TOKENTYPE.RIGHT_PAREN);
                }
                else { throw new Exception("Error - Mismatching right parenthesis in integer expression"); }
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