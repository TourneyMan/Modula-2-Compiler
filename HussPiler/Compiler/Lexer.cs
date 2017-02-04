using System;
using System.Collections;   // ArrayList, HashTable

namespace Compiler
{
    class Lexer
    {
        // Track defaults and file locations.
        FileManager fm = FileManager.Instance;

        // The hastable of Modula-2 keywords
        Hashtable keywords = new Hashtable();

        // keep track of total tokens
        private int tokenCount = 0;

        // The single object instance for this class.
        private static Lexer lexInstance;

        // To prevent access by more than one thread. This is the specific lock 
        //    belonging to the Lexer Class object.
        private static Object lexLock = typeof(Lexer);

        /// <summary>
        /// Instead of a constructor, we offer a static method to return the onlyinstance.
        /// </summary>
        private Lexer() { } // private constructor so no one else can create one.

        /// <summary>
        /// returns the single instnace of the lexer object
        /// </summary>
        public static Lexer Instance
        {
            get
            {
                lock (lexLock)
                {
                    if (lexInstance == null)
                    {
                        lexInstance = new Lexer();
                    }
                    return lexInstance;
                }
            }
        } // Lexer Instance

        /// <summary>
        /// Reset the lexing process.
        /// </summary>
        public void Reset()
        {
            // set the file position back to the starting point
            fm.SOURCE_READER.Reset();

            // reset the tokenList to just the header
            fm.ResetTokenList();

            // we don't have a token yet
            tokenCount = 0;

        } // Reset
        
        /// <summary>
        /// This is the principal function of this class. The Token object is created,
        ///     loaded with correct information, and returned.
        /// </summary>
        /// <returns>Token loaded with the correct data.
        /// If lexing has failed, the TOKENTYPE is T_ERROR</returns>
        public Token GetNextToken()
        {
            char nextChar = fm.SOURCE_READER.GetNextOneChar();

            // if we find a token...create a new token and return it
            return new Token(Token.TOKENTYPE.EOF, "EOF", -1);

            // if it was not a valid token...throw an exception that will alert the users
            throw new Exception("Temp Exception");

        } // GetNextToken

        /// <summary>
        /// Token List string in FileManager is updated with all tokens from the source file
        ///    attractively formatted.
        /// </summary>
        public void ListTokens()
        {
            Reset(); // reset prior to lexing a file
            fm.TOKEN_LIST = "Token list:\r\n\r\nTK\tLn\tType\t\t\tLexeme\r\n\r\n";
            bool endOfFile = false;

            keywords[0] = "ERROR"; keywords[1] = "AND"; keywords[2] = "ARRAY"; keywords[3] = "BEGIN"; keywords[4] = "CARDINAL"; keywords[5] = "CONST";
            keywords[6] = "DIV"; keywords[7] = "DO"; keywords[8] = "ELSE"; keywords[9] = "END"; keywords[10] = "EXIT"; keywords[11] = "FOR"; keywords[12] = "IF";
            keywords[13] = "INTEGER"; keywords[14] = "LOOP"; keywords[15] = "MOD"; keywords[16] = "MODULE"; keywords[17] = "NOT"; keywords[18] = "OF";
            keywords[19] = "OR"; keywords[20] = "PROCEDURE"; keywords[21] = "REAL"; keywords[22] = "THEN"; keywords[23] = "TYPE"; keywords[24] = "VAR";
            keywords[25] = "WHILE"; keywords[26] = "WRCARD"; keywords[27] = "WRINT"; keywords[28] = "WRLN"; keywords[29] = "CLS";
            keywords[30] = "WRREAL";
            keywords[31] = "RDCARD";
            keywords[32] = "RDINT";
            keywords[33] = "RDREAL";
            keywords[34] = "WRSTR";

            while (!endOfFile)
            {
                Token nextToken = GetNextToken();
                fm.TOKEN_LIST += tokenCount.ToString() + "\t" + nextToken.ToString();
                if (nextToken.tokType == Token.TOKENTYPE.EOF) { endOfFile = true; }
                tokenCount++;
            }


        } // ListTokens

    } // Lexer

} // Compiler namespace