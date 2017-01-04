using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms; // Error window

namespace Compiler
{
    /// <summary>
    /// Program level error codes
    /// </summary>
    public enum ERROR_CODE
    {
        UKNOWN_ERROR = -1,

        /*0*/   NONE,                   TOKEN_INVALID,          FILE_NOT_OPEN,
                FILE_OPEN_ERROR,        FILE_SAVE_ERROR,        FILE_CLOSE_ERROR,

        /*6*/   SYMBOL_NOT_IN_SCOPE,    SYMBOL_UNDEFINED,       SYMBOL_UNITIALIZED,
                VAR_REDECLARATION,      CONST_REDECLARATION,    CONST_REDEFINITION,

        /*12*/  OUT_OF_RANGE,           INVALID_TYPE,           TYPE_REDECLARATION,
                TYPE_REDEFINITION,      PROC_REDECLARATION

    } // ERROR_CODE

    /// <summary>
    /// Basic static class for handling errors
    /// </summary>
    class ErrorHandler
    {
        /// <summary>
        /// Default constructor, not used
        /// </summary>
        private ErrorHandler() { }

        public static void Error(ERROR_CODE err, string location, string comment, int line = -1)
        {
            FileManager fm = FileManager.Instance;
            string message;

            fm.CURRENT_ERROR = err;

            if(line == -1)
                message = string.Format("Error {0}: {1}\r\n{2}",
                                        (int)err,
                                        err.ToString(),
                                        comment);
            else
                message = string.Format("Error {0}: {1} at line: {2}\r\n{3}",
                                        (int)err,
                                        err.ToString(),
                                        line,
                                        comment);

            // add error to log
            AddToLog(message);

            // show error window
            if (fm.SHOW_ERROR_WINDOW)
                MessageBox.Show(message,
                                fm.COMPILER + " - " + location,
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Error,
                                MessageBoxDefaultButton.Button1,
                                MessageBoxOptions.RightAlign);
            
        } // Error

        /// <summary>
        /// Add error string to class log
        /// </summary>
        /// <param name="errorString"></param>
        private static void AddToLog(string errorString)
        {
            FileManager fm = FileManager.Instance;
            DateTime dt = DateTime.Now;

            fm.ERROR_LOG += string.Format("{0}\r\n#{1}: {2}\r\n====================================================\r\n",
                                            dt.ToString(),
                                            ++fm.ERROR_COUNT,
                                            errorString);
        } // AddToLog
        
    } // ErrorHandler class

} // Compiler namespace