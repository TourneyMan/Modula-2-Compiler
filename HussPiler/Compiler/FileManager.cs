using System;
using System.IO;    // FileStream, Directory, etc.

namespace Compiler
{
    class FileManager
    {
        private string compilerName,    // branding for compiler, e.g. "BrewPiler or TomPile"
                        sourceDIR,      // name of source and compilation directory, e.g. "C:\Compiler\MODS\"
                        masmDIR,        // name of binary directory, e.g. "C:\masm32\"
                        sourceFile,     // name of M2 source file, no dir, e.g. "01_Test.mod"
                        errorLog,       // log string for errors
                        tokenList;      // giant string to hold what will go into the txt file

        // number of errors encountered
        private int errorCount; 
        
        // current error encountered
        private ERROR_CODE currentError;
    
        // allow error window to be displayed
        private bool showErrorWindow;

        // reference to the SourceReader and current open source file (as an object)
        private SourceReader sourceReader;

        /// <summary>
        /// Static instance of this class
        /// </summary>
        private static FileManager fmInstance;

        /// <summary>
        /// To prevent access by more than one thread. This is the specific lock 
        /// belonging to the FileManager Class object.
        /// </summary>
        private static Object fmLock = typeof(FileManager);

        /// <summary>
        /// Instead of a constructor, we offer a static method to return the only instance.
        /// - Private constructor so no one else can create one.
        /// </summary>
        private FileManager() { }

        /// <summary>
        /// Management for static instance of this class
        /// </summary>
        public static FileManager Instance
        {
            get
            {
                lock (fmLock)
                {
                    if (fmInstance == null) // if no instnace exists, we need to create one
                    {
                        fmInstance = new FileManager();

                        // initalize FileManager variables
                        fmInstance.Initialize();
                    }
                    return fmInstance; // return the only instance of this calss
                }
            }

        } // Instance

        /// <summary>
        /// called during initial creation of the FileManager instance
        /// </summary>
        private void Initialize()
        {
            // Set the name of the comiler, e.g. "Brewpiler or Tompiler".
            //  Compiler name is used on all forms and error messages.
            COMPILER = "HussPiler";

            // set the default path to the masm folder...usually located in the c: directory
            MASM_DIR = @"C:\masm32\";

            // set the default souce directory based on which computer we are working from
            if (Directory.Exists(@"D:\StudentCompilers\HussPiler"))    // working from John's Computer
                SOURCE_DIR = @"D:\StudentCompilers\HussPiler\MODS\";
            else if (Directory.Exists(@"C:\Users\john.broere\Desktop\HussPiler"))    // working from lab computer
                SOURCE_DIR = @"C:\Users\john.broere\Desktop\HussPiler\MODS\";
            else if (Directory.Exists(@"E:\Documents\GitHub\HussPiler\MODS\"))    // working from Jacob's desktop
                SOURCE_DIR = @"E:\Documents\GitHub\HussPiler\MODS\";

            // set the default source file...change this to help speed up debugging
            SOURCE_FILE = "01_Test.mod";

            // get a copy of a SourceReader to use...there will only be one and it will be accessed through the FileManager
            sourceReader = new SourceReader();

            // reset all error variables
            ErrorReset();

        } // Initialize

        /// <summary>
        /// Reset the error variables
        /// </summary>
        public void ErrorReset()
        {
            ERROR_LOG = "";
            ERROR_COUNT = 0;
            CURRENT_ERROR = ERROR_CODE.NONE;
            SHOW_ERROR_WINDOW = true;

        } // ErrorReset

        /// <summary>
        /// Resets the tokenList
        /// </summary>
        public void ResetTokenList()
        {
            tokenList = "";
        } //ResetTokenList

        /**********************************************************************************************************************
            GET AND SET FUNCTIONS
        **********************************************************************************************************************/

        /// <summary>
        /// set or get the compiler name e.g. "BrewPiler | StudentPiler"
        /// </summary>
        public string COMPILER
        {
            get { return compilerName; }
            set { compilerName = value; }

        } // COMPILER

        /// <summary>
        /// set or get the source directory name e.g. "C:\Compilers\TEST_MOD\"
        /// </summary>
        public string SOURCE_DIR
        {
            get { return sourceDIR; }
            set { sourceDIR = value; }

        } // SOURCE_DIR

        /// <summary>
        /// set or get the MASM directory name e.g. "C:\Compilers\MASM32\"
        /// </summary>
        public string MASM_DIR
        {
            get { return masmDIR; }
            set { masmDIR = value; }

        } // MASM_DIR

        /// <summary>
        /// set or get the source file name e.g. "01_Test.mod"
        /// </summary>
        public string SOURCE_FILE
        {
            get { return sourceFile; }
            set { sourceFile = value; }

        } // SOURCE_FILE

        /// <summary>
        /// return the source name without ".mod e.g. 01_Test"
        /// </summary>
        public string SOURCE_NAME
        { get { return sourceFile.Substring(0, sourceFile.Length - 4); } } // SOURCE_NAME

        /// <summary>
        /// set and get the error log
        /// </summary>
        public string ERROR_LOG
        {
            get { return errorLog; }
            set { errorLog = value; }

        } // ERROR_LOG

        /// <summary>
        /// set and get the error count
        /// </summary>
        public int ERROR_COUNT
        {
            get { return errorCount; }
            set { errorCount = value; }

        } // ERROR_COUNT

        /// <summary>
        /// set and get the current error
        /// </summary>
        public ERROR_CODE CURRENT_ERROR
        {
            get { return currentError; }
            set { currentError = value; }

        } // CURRENT_ERROR

        /// <summary>
        /// get and set error window status
        /// </summary>
        public bool SHOW_ERROR_WINDOW
        {
            get { return showErrorWindow; }
            set { showErrorWindow = value; }

        } // SHOW_ERROR_WINDOW

        /// <summary>
        /// set or get the current source reader
        /// </summary>
        public SourceReader SOURCE_READER
        {
            get { return sourceReader; }
            set { sourceReader = value; }

        } // SOURCE_READER

        /// <summary>
        /// set or get the tokenList string
        /// </summary>
        public string TOKEN_LIST
        {
            get { return tokenList; }
            set { tokenList = value; }

        } // SOURCE_DIR

        /**********************************************************************************************************************
            Folder and File FUNCTIONS
        **********************************************************************************************************************/

        /// <summary>
        /// used by ErrorHandler to file ErrorLog
        /// </summary>
        public void FileErrorLog()
        {
            Filer.WriteStringToFile(ERROR_LOG, SOURCE_DIR + @"error_log.txt");

        } // FileErrorLog

        /// <summary>
        /// Resets the assembly directory as a blank folder
        /// </summary>
        public void ResetASMDIR()
        {
            Filer.CreateCleanDir((SOURCE_DIR + SOURCE_FILE + COMPILER).Replace(".mod", ""));
        } // ResetASMDIR

        /// <summary>
        /// Writes tokenList to the file that corresponds to the given Source File 
        /// </summary>
        public void FileTokenList()
        {
            Filer.WriteStringToFile(tokenList, (SOURCE_DIR + SOURCE_FILE).Replace(".mod", "") + COMPILER + "\\" + (SOURCE_FILE + "_Tokens.txt").Replace(".mod", ""));
        } // ResetASMDIR

    } // FileManager class

} // Compiler namespace