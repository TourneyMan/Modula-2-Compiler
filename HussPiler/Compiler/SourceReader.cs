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
                        endLineLastRead,    // did we reach an end of line on the last read?
                        endOfFile,          // have we reached the end of the file?
                        needNewLine;        // did we just get a new line?

        private string  fileName,           // path and file name
                        inputLine;          // the current input line

        private int     currentPos,         // current position in the input line
                        lineNumber;         // current line number in the source file

        /// <summary>
        /// Constructor
        /// </summary>
        public SourceReader()
        {
            needNewLine = false;
            endOfFile = false;
            isOpen = false;             // the file has not been opened yet
            fm.SOURCE_READER = this;    // register the current source reader object with the file mananger
            fileName = fm.SOURCE_DIR + fm.SOURCE_FILE;
            currentPos = 0;
            lineNumber = 1;
        } // SourceReader

        // This (sort of) corresponds to the C# (and C++ and C) end of file "character."
        public const char EOF_SENTINEL = (char)255;

        /// <summary>
        /// Opens the file referred to by Source Directory and Source File in the FileManager instance.
        /// </summary>
        /// <returns> Returns true is successful in opening a file or if a file is already open; false otherwise.</returns>
        public bool Open()
        {
            if (!isOpen)
            {   // Open the text file using a stream reader.
                if (File.Exists(fileName))
                {
                    streamReader = new StreamReader(fileName);
                    isOpen = true;
                    inputLine = streamReader.ReadLine();
                    endLineLastRead = false;
                    return true;
                }

                else
                {
                    ErrorHandler.Error(ERROR_CODE.FILE_OPEN_ERROR, "Get a Char Form", "Directory and file do not create valid file path");
                    return false;
                }
            }
            return true;
        } // Open

        /// <summary>
        /// Resets local vars and the streamReader so that reading is restarted at the beginning of the file
        /// </summary>
        /// <returns>Returns true if source reader was properly reset; false otherwise.</returns>
        public bool Reset()
        {
            if (isOpen)
            {
                needNewLine = false;
                endOfFile = false;
                lineNumber = 1; // Reset vars to default vals
                currentPos = 0;
                endLineLastRead = false;
                streamReader.BaseStream.Position = 0; //Setting the streamReader back to the beginning of the file
                streamReader.DiscardBufferedData();
                inputLine = streamReader.ReadLine(); 

                return true;
            }
            ErrorHandler.Error(ERROR_CODE.FILE_NOT_OPEN, "Get a Char Form", "Could not get next char because file not open");
            return false;

        } // Reset

        /// <summary>
        /// Sets the inputLine to the next line. Sets/Resets appropriate vars
        /// </summary>
        /// <returns>Returns whether or not there was a next line</returns>
        private bool GetNextLine()
        {
            inputLine = streamReader.ReadLine();
            lineNumber++;
            currentPos = 0; //Start at the beginning of the line
            needNewLine = true;
            return true;
        } // GetNextLine

        /// <summary>
        /// Gets the next character of the file, preparing for a new line if the end of the line has been reached.
        /// </summary>
        /// <returns>Returns next char of the file. Returns char 255 to signify EOF</returns>
        public char GetNextOneChar()
        {
            if (isOpen)
            {
                if (endOfFile) { return EOF_SENTINEL; }

                if (needNewLine) { GetNextLine(); }

                if (endLineLastRead) { needNewLine = true;  endLineLastRead = false;  return '\r'; }

                if (inputLine != null && !inputLine.Equals(""))
                {
                    char returnChar = inputLine[currentPos];
                    if (currentPos == inputLine.Length - 1) { endLineLastRead = true; }
                    else { currentPos++; endLineLastRead = false; needNewLine = false; }
                    return returnChar;
                }
                else if (streamReader.Peek() == -1)
                {
                    endOfFile = true;
                    return EOF_SENTINEL;
                }
                else
                {
                    return GetNextOneChar();
                }
            }

            ErrorHandler.Error(ERROR_CODE.FILE_NOT_OPEN, "Get a Char Form", "Could not get next char because file not open");
            return EOF_SENTINEL;



        } // GetNextOneChar

        /// <summary>
        /// Pushes back the SourceReader so that the next character read by GetNextOneChar will be the character directly before the current one being viewed.
        /// Stays at the beginning of the line if already there.
        /// </summary>
        public void PushBackOneChar()
        {
            if (isOpen)
            {
                if (endLineLastRead) { currentPos--;  endLineLastRead = false; }
                else if (needNewLine) { needNewLine = false; }
                else { currentPos -= 2; }
                if (currentPos < 0) { currentPos = 0; }
            }
            else { ErrorHandler.Error(ERROR_CODE.FILE_NOT_OPEN, "Get a Char Form", "Could not push back char because file not open"); }
        } // PushBackOneChar

        /// <summary>
        /// the current line number of the source file
        /// </summary>
        public int LINE_NUMBER
        { get { return lineNumber; } } // LINE_NUMBER

        /// <summary>
        /// Closes this instance of SourceReader
        /// </summary>
        /// <returns>Returns true if SourceReader was successfully closed; false otherwise.</returns>
        public bool Close()
        {
            try
            {
                fm.SOURCE_READER = null; //This is no longer the FileManager's Source Reader :(
                streamReader.Close(); //Close the streamReader
                return true;
            }
            catch (Exception e) {
                //ErrorHandler.Error(ERROR_CODE.FILE_CLOSE_ERROR, "Get a Char Form", "Could not close source reader");
                return false;
            }


        } // Close

    } // SourceReader class

} // Compiler namespace