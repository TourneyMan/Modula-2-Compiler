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

        //Set to true when characters have been l
        //private bool needToCleanUpTokens = false;

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
            bool endOfToken = false;
            bool isInt = false;
            bool firstChar = true;
            String buildString = "";
            while (!endOfToken)
            {
                char nextChar = fm.SOURCE_READER.GetNextOneChar();

                //Stop looping when we find something indicating the end of a Token
                if (nextChar == '\r' || nextChar == ' ' || nextChar == SourceReader.EOF_SENTINEL || nextChar == '\t') 
                {
                    //If we don't have anything in the string yet and its not EOF, just ignore
                    if (!buildString.Equals("") || nextChar == SourceReader.EOF_SENTINEL) { endOfToken = true; } 
                    else { endOfToken = false; }
                }

                //Individual characters that indicate very specific Token Types
                else if (nextChar == '(' || nextChar == ')' || nextChar == ';' || nextChar == '.' || nextChar == ':' || nextChar == ',' || nextChar == '"' || nextChar == '+'
                    || nextChar == '-' || nextChar == '=' || nextChar == '*' || nextChar == '/' || nextChar == '[' || nextChar == ']') 
                {
                    if (!firstChar)
                    {
                        fm.SOURCE_READER.PushBackOneChar();
                        fm.SOURCE_READER.GetNextOneChar();
                        endOfToken = true;
                    }
                    else
                    {
                        if (nextChar == '(') {
                            if (fm.SOURCE_READER.GetNextOneChar() != '*') {
                                fm.SOURCE_READER.PushBackOneChar();
                                fm.SOURCE_READER.GetNextOneChar();
                                return new Token(Token.TOKENTYPE.LEFT_PAREN, "(", fm.SOURCE_READER.LINE_NUMBER);
                            }
                            else {

                                bool isComment = true;
                                while (isComment)
                                {
                                    nextChar = fm.SOURCE_READER.GetNextOneChar();
                                    if (nextChar == '*')
                                    {
                                        if (fm.SOURCE_READER.GetNextOneChar() == ')') {
                                            isComment = false;
                                        }
                                    }
                                }
                            }
                        }

                        //For Strings
                        else if (nextChar == '"')
                        {
                            while (!endOfToken)
                            {
                                nextChar = fm.SOURCE_READER.GetNextOneChar();
                                if (nextChar != '"') { buildString += nextChar; }
                                else { return new Token(Token.TOKENTYPE.STRING, buildString, fm.SOURCE_READER.LINE_NUMBER); }
                            }
                        }

                        else if (nextChar == ':')
                        {
                            if (fm.SOURCE_READER.GetNextOneChar() == '=') { return new Token(Token.TOKENTYPE.ASSIGN, ":=", fm.SOURCE_READER.LINE_NUMBER); }
                            else
                            {
                                fm.SOURCE_READER.PushBackOneChar();
                                fm.SOURCE_READER.GetNextOneChar();
                                return new Token(Token.TOKENTYPE.COLON, ":", fm.SOURCE_READER.LINE_NUMBER);
                            }
                        }

                        //Simple, single character tokens
                        else if (nextChar == ')') { return new Token(Token.TOKENTYPE.RIGHT_PAREN, ")", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '.') { return new Token(Token.TOKENTYPE.DOT, ".", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == ';') { return new Token(Token.TOKENTYPE.SEMI_COLON, ";", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == ',') { return new Token(Token.TOKENTYPE.COMMA, ",", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '+') { return new Token(Token.TOKENTYPE.PLUS, "+", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '-') { return new Token(Token.TOKENTYPE.MINUS, "-", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '=') { return new Token(Token.TOKENTYPE.EQUAL, "=", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '*') { return new Token(Token.TOKENTYPE.MULT, "*", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '/') { return new Token(Token.TOKENTYPE.SLASH, "/", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == '[') { return new Token(Token.TOKENTYPE.LEFT_BRACK, "[", fm.SOURCE_READER.LINE_NUMBER); }
                        else if (nextChar == ']') { return new Token(Token.TOKENTYPE.RIGHT_BRACK, "]", fm.SOURCE_READER.LINE_NUMBER); }
                    }

                }

                //If we have the start of a string
                /*else if (nextChar == '"')
                {
                    //if (buildString.Equals(""))
                    //{
                        while (!endOfToken)
                        {
                            nextChar = fm.SOURCE_READER.GetNextOneChar();
                            if (nextChar != '"') { buildString += nextChar; }
                            else { return new Token(Token.TOKENTYPE.STRING, buildString, fm.SOURCE_READER.LINE_NUMBER); }
                        }
                    /*}
                    else
                    {
                        fm.SOURCE_READER.PushBackOneChar();
                        fm.SOURCE_READER.GetNextOneChar();
                        endOfToken = true;
                    }*/
                //}
                else if (firstChar && Char.IsNumber(nextChar))
                {
                    isInt = true;
                    firstChar = false;
                    buildString += nextChar;
                }
                else
                {
                    if (isInt && !Char.IsNumber(nextChar))
                    {
                        //Error -- Invalid Token
                    }
                    buildString += nextChar;
                    firstChar = false;
                }
            }

            bool matchesKeyword = false;
            int keywordNum = -2;
            foreach (DictionaryEntry entry in keywords)
            {
                if (entry.Value.Equals(buildString))
                {
                    keywordNum = (int)entry.Key;
                    matchesKeyword = true;
                }
            }

            if (matchesKeyword) { return new Token((Token.TOKENTYPE)keywordNum, buildString, fm.SOURCE_READER.LINE_NUMBER); }
            else if (isInt) { return new Token(Token.TOKENTYPE.INT_NUM, buildString, fm.SOURCE_READER.LINE_NUMBER); }
            else if (!buildString.Equals("")) { return new Token(Token.TOKENTYPE.ID, buildString, fm.SOURCE_READER.LINE_NUMBER); }
            else { return new Token(Token.TOKENTYPE.EOF, "End Of File", fm.SOURCE_READER.LINE_NUMBER); } // if we find a token...create a new token and return it

            // if it was not a valid token...throw an exception that will alert the users
            throw new Exception("Temp Exception");

        } // GetNextToken

        /// <summary>
        /// Token List string in FileManager is updated with all tokens from the source file
        ///    attractively formatted.
        /// </summary>
        public void ListTokens()
        {
            keywords[0] = "ERROR"; keywords[1] = "AND"; keywords[2] = "ARRAY"; keywords[3] = "BEGIN"; keywords[4] = "CARDINAL"; keywords[5] = "CONST";
            keywords[6] = "DIV"; keywords[7] = "DO"; keywords[8] = "ELSE"; keywords[9] = "END"; keywords[10] = "EXIT"; keywords[11] = "FOR"; keywords[12] = "IF";
            keywords[13] = "INTEGER"; keywords[14] = "LOOP"; keywords[15] = "MOD"; keywords[16] = "MODULE"; keywords[17] = "NOT"; keywords[18] = "OF";
            keywords[19] = "OR"; keywords[20] = "PROCEDURE"; keywords[21] = "REAL"; keywords[22] = "THEN"; keywords[23] = "TYPE"; keywords[24] = "VAR";
            keywords[25] = "WHILE"; keywords[26] = "WRCARD"; keywords[27] = "WRINT"; keywords[28] = "WRLN"; keywords[29] = "CLS"; keywords[30] = "WRREAL";
            keywords[31] = "RDCARD"; keywords[32] = "RDINT"; keywords[33] = "RDREAL"; keywords[34] = "WRSTR";

            Reset(); // reset prior to lexing a file
            fm.TOKEN_LIST = "Token list:\r\n\r\n TK  Ln Type                      Lexeme\r\n\r\n";
            bool endOfFile = false;

            while (!endOfFile)
            {
                Token nextToken = GetNextToken();
                fm.TOKEN_LIST += string.Format("{0, 3} {1,0}", tokenCount.ToString(), nextToken.ToString());
                if (nextToken.tokType == Token.TOKENTYPE.EOF) { endOfFile = true; }
                tokenCount++;
            }


        } // ListTokens

    } // Lexer

} // Compiler namespace