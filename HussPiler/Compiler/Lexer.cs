using System;
using System.Collections;   // ArrayList, HashTable

namespace Compiler
{
    class Lexer
    {
        // Track defaults and file locations.
        FileManager fm = FileManager.Instance;

        // The hastable of Modula-2 keywords
        Hashtable keywords;

        // keep track of total tokens
        private int tokenCount;

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
            // reset prior to lexing a file
            Reset();

        } // ListTokens

    } // Lexer

} // Compiler namespace