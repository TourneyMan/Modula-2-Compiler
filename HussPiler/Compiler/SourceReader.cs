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
            isOpen = false;             // the file has not been opened yet
            fm.SOURCE_READER = this;    // register the current source reader object with the file mananger
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
                fileName = fm.SOURCE_DIR + fm.SOURCE_FILE;
                if (File.Exists(fileName))
                {
                    needNewLine = false;
                    endOfFile = false;
                    streamReader = new StreamReader(fileName);
                    isOpen = true;
                    inputLine = streamReader.ReadLine();
                    endLineLastRead = false;
                    currentPos = 0;
                    lineNumber = 1;
                    return true;
                }

                else
                {
                    ErrorHandler.Error(ERROR_CODE.FILE_OPEN_ERROR, "Source Reader", "Could not open because directory and file do not create valid file path");
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
                currentPos = 0;
                lineNumber = 1;
                return true;
            }

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
            needNewLine = false;

            if (inputLine == null) { return false; }
            if (inputLine.Equals("")) { return true; }

            for (int i = 0; i < inputLine.Length; i++)
            {
                if (inputLine[i] != '\t' && inputLine[i] != ' ' && inputLine[i] != '\r' && inputLine[i] != '\n') { return false; }
            }

            return true;
            /*inputLine = streamReader.ReadLine();
            lineNumber++;
            currentPos = 0; //Start at the beginning of the line
            needNewLine = true;
            return true;*/
        } // GetNextLine

        /// <summary>
        /// Gets the next character of the file, preparing for a new line if the end of the line has been reached.
        /// </summary>
        /// <returns>Returns next char of the file. Returns char 255 to signify EOF</returns>
        public char GetNextOneChar()
        {
            if (isOpen)
            {
                if (endOfFile) { return EOF_SENTINEL; } //If we are done, just keep returning EOF

                else if (endLineLastRead) { needNewLine = true; endLineLastRead = false; return '\r'; } //We need to return \r and prepare for a new line


                if (needNewLine) { while(GetNextLine()) { } } //Keep getting the next line until it has something important on it


                if (streamReader.Peek() == -1 && inputLine == null) { endOfFile = true; return EOF_SENTINEL; } //Check if we have reached the end

                else //If the code has gotten here, there are no special cases -- treat as normal char, not at end of line or file
                {
                    char returnChar = inputLine[currentPos];
                    if (currentPos == inputLine.Length - 1) { endLineLastRead = true; }
                    else { currentPos++; endLineLastRead = false; needNewLine = false; }
                    return returnChar;
                }
            }

            ErrorHandler.Error(ERROR_CODE.FILE_NOT_OPEN, "Source Reader", "Could not get next char because file not open");
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
            else { ErrorHandler.Error(ERROR_CODE.FILE_NOT_OPEN, "Source Reader", "Could not push back char because file not open"); }
        } // PushBackOneChar

        /// <summary>
        /// Prepares the SourceReader so that next time a char is gotten, the char that was returned last is returned again
        /// </summary>
        public void CheckSameCharNext()
        {
            PushBackOneChar();
            GetNextOneChar();
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
                fm.SOURCE_READER = new SourceReader(); //This is no longer the FileManager's Source Reader :(
                streamReader.Close(); //Close the streamReader
                return true;
            }
            catch (Exception e) {
                return false;
            }


        } // Close

    } // SourceReader class

} // Compiler namespace