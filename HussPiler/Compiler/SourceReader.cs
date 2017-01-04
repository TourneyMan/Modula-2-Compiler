using System;
using System.IO;

namespace Compiler
{
    class SourceReader
    {
        // file names, paths, and defaults
        FileManager fm = FileManager.Instance;
        
        StreamReader    streamReader;       // the Modula-2 source file

        private bool    isOpen,             // is the file open yet?
                        endLineLastRead;    // did we reach an end of line on the last read?

        private string  fileName,           // path and file name
                        inputLine;          // the current input line

        private int     currentPos,         // current position in the input line
                        lineNumber;         // current line number in the source file

        /// <summary>
        /// Constructor
        /// </summary>
        public SourceReader()
        {
            isOpen = false;             // the file has not been opened yet
            fm.SOURCE_READER = this;    // register the current source reader object with the file mananger

        } // SourceReader

        // This (sort of) corresponds to the C# (and C++ and C) end of file "character."
        public const char EOF_SENTINEL = (char)255;
                
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool Open()
        {
            return false;

        } // Open

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool Reset()
        {
            return false;

        } // Reset

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        private bool GetNextLine()
        {
            return false;

        } // GetNextLine

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public char GetNextOneChar()
        {
            return ' ';

        } // GetNextOneChar

        /// <summary>
        /// 
        /// </summary>
        public void PushBackOneChar()
        {
            
        } // PushBackOneChar

        /// <summary>
        /// the current line number of the source file
        /// </summary>
        public int LINE_NUMBER
        { get { return lineNumber; } } // LINE_NUMBER

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool Close()
        {
            return false;

        } // Close

    } // SourceReader class

} // Compiler namespace