using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compiler
{
    /// <summary>
    /// A token is a category of lexemes.
    /// 
    /// Some tokens are keywords like "MODULE". Some tokens are symbols; the token of type
    ///    PLUS is the symbol "+". Some tokens are a large set; some tokens of type
    ///    INTEGER are "73" and "255".
    /// 
    /// The enumerations below include all the tokens that we need to recognize.
    /// 
    /// Note that the Modula-2 User's Manual offers two ways of saying NOT EQUAL 
    ///    (pp. 96, 97, and 110). Our code only uses the LessThanGreaterThan token.
    /// 
    /// Many errors are reported by TOKENTYPE which is just a number (like 34 for ID).
    /// Therefore, enumeration numbers have been added for tokens in the left column as a
    ///    convenience during debugging.
    ///    
    /// Author: Tom Fuller
    /// Date: January 6, 2007
    /// 
    /// Modified By: John Broere
    /// Date: Spring 2013
    /// </summary>
    class Token
    {
        /// <summary>
        /// Type for defining tokens
        /// </summary>
        public enum TOKENTYPE
        {
            /* 0*/
            ERROR = 0, AND, ARRAY, BEGIN,
            /* 4*/
            CARDINAL, CONST, DIV, DO,
            /* 8*/
            ELSE, END, EXIT, FOR, IF,
            /*13*/
            INTEGER, LOOP, MOD, MODULE,
            /*17*/
            NOT, OF, OR, PROCEDURE,
            /*21*/
            REAL, THEN, TYPE, VAR,
            /*25*/
            WHILE, WRCARD, WRINT, WRLN, CLS,
            /*30*/
            WRREAL, RDCARD, RDINT, RDREAL, WRSTR,

            /*35*/
            ID, CARD_NUM, REAL_NUM, INT_NUM,

            /*39*/
            STRING,

            /*40*/
            ASSIGN, COLON, COMMA, DOT,
            /*44*/
            DOT_DOT, EQUAL, LEFT_BRACK, LEFT_PAREN,
            /*48*/
            MINUS, MULT, NOT_EQ, PLUS,
            /*52*/
            RIGHT_BRACK, RIGHT_PAREN, SEMI_COLON, SLASH,
            /*56*/
            GRTR_THAN, GRTR_THAN_EQ, LESS_THAN, LESS_THAN_EQ,

            /* The two comment tokens are not presently used */
            /*60*/
            COMMENT_BEG, COMMENT_END,

            /*62*/
            EOF
        };

        /*********************************************************************************
         There are 35 reserved keywords we need to recognize in Modula-2 source code files.
            Note that enumerated types 0 - 34 above correspond precisely to these keywords. 
            Some number types are not used except by very ambitious students: CARDINAL, REAL.
            Some statements are also reserved for the fearless: WHILE, DO, FOR.
        *********************************************************************************/
        public static int keywordCount = 35;

        /*********************************************************************************
          The Token class itself stores information about a single token.
         *********************************************************************************/
        public TOKENTYPE tokType;   // what token (i.e. class of lexemes)
        public string lexName;      // lexeme name: reserved word, identifier
        public int lineNumber;      // the (source file)line containing the token

        /// <summary>
        /// default constructor, not used
        /// </summary>
        public Token()
        {
            tokType = Token.TOKENTYPE.ERROR;
            lexName = "blank token";
            lineNumber = 0;

        } // Token
        
        /// <summary>
        /// normal constructor with tokentype, lexeme and line number
        /// </summary>
        /// <param name="inTokType"></param>
        /// <param name="inName"></param>
        /// <param name="inLine"></param>
        public Token(Token.TOKENTYPE inTokType, string inName, int inLine)
        {
            tokType = inTokType;
            lexName = inName;
            lineNumber = inLine;

        } // Token
        
        /// <summary>
        /// Returns nicely formatted information about this Token
        /// </summary>
        /// <returns>a formatted string of the current token</returns>
        public override string ToString()
        {
            return string.Format("{0,3}:Token: {1,-2}: {2,-15} {3,-100}\r\n", lineNumber.ToString(), ((int)tokType).ToString(), tokType, lexName);
        } // ToString

    } // Token

} // Compiler namespace