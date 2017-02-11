using System;

namespace Compiler
{
    class Facade
    {
        // singleton instances
        private FileManager fm = FileManager.Instance;
        private Lexer lexer = Lexer.Instance;
        private Parser parser = Parser.Instance;

        /// <summary>
        /// Default constructor
        /// </summary>
        public Facade() { }

        /// <summary>
        /// Create a list of all tokens in the current source file.
        /// </summary>
        public void ListTokens()
        {
            try // to lex the current file and list the tokens
            {
                fm.ResetASMDIR();          // create a clean assembly directory
                fm.ResetTokenList();        // reset teken list

                fm.SOURCE_READER.Open();   // open current file listed in file manager
                lexer.ListTokens();        // lex file and list tokens
                fm.SOURCE_READER.Close();  // close current file

                fm.FileTokenList();        // save token list to assembly directory
            }
            catch (Exception e)
            {
                ErrorHandler.Error(ERROR_CODE.UKNOWN_ERROR,
                                    "Facade - List Tokens",
                                    e.ToString());
            }

        } // listTokens

        /// <summary>
        /// Create a test set of symbols and  file them
        /// </summary>
        public void TestSymTable()
        {
            fm.ResetSymbolList();

            parser.TestSymbolTable();

            fm.FileTestSymbols();

        } // TestSymTable

    } // Facade class

} // Compiler namespace