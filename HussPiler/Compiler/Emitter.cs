using System;
using System.Collections;   // ArrayList

namespace Compiler
{
    /// <summary>
    /// Emitter is a singleton class that creates assembler files. It works with the
    /// FileManager to keep track of what assembler code to write to what file.
    /// A number of assembler files are used during compilations:
    ///    string.inc
    ///    proclist.inc
    ///    main.asm
    ///    etc.
    /// </summary>
    class Emitter
    {
        // We will often need to work with the FileManager.
        private FileManager fm = FileManager.Instance;

        // We maintain an ArrayList of strings that correspond to the main procedure (procedure 0) 
        //    and other procedures.
        static ArrayList procedureStrings;

        // This is the index to the ArrayList of strings. When 0 it refers to the main procedure.
        //    When > 0 it points to the current procedure being built (statements) by the emitter.
        static int currentProcedure;

        // how much memory is needed for the main procedure?
        static int mainMemUse;          

        static string stringConstants;  // stores all strings used in the program
        static int nextStringNum;       // remembers the next available string number
        
        // The single object instance for this class.
        private static Emitter c_eInstance;

        // To prevent access by more than one thread. This is the specific lock 
        //    belonging to the Emitter Class object.
        private static Object c_eLock = typeof(Emitter);

        // Instead of a constructor, we offer a static method to return the only instance.
        private Emitter() { } // private constructor so no one else can create one.

        /// <summary>
        /// Management for static instance of this class
        /// </summary>
        public static Emitter Instance
        {
            get
            {
                lock (c_eLock)
                {
                    // if this is the first request, initialize the one instance
                    if (c_eInstance == null)
                    {
                        c_eInstance = new Emitter();
                        c_eInstance.Reset();
                    }

                    // in either case, return a reference to the only instance
                    return c_eInstance;
                }
            }

        } // Emitter Instance

        /// <summary>
        /// PRE:  The single emitter exists. This must be called BEFORE the main procedure
        ///    is entered. It sets the current procedure index to -1.
        /// POST: We are ready to start parsing and related assembly.
        /// </summary>
        public void Reset()
        {
            // create the array of strings and add the first (main) string
            procedureStrings = new ArrayList();
            currentProcedure = -1; // thus the main procedure will have index 0

            // initialize the string constant storage
            stringConstants = ";===== string constants for the program: ======\r\n";
            nextStringNum = 0; // the next string constant will be number 0 ("Str0  DB ...")

        } // Reset

        // #########################################################################################
        // ASSEMBLER METHODS   ASSEMBLER METHODS   ASSEMBLER METHODS   ASSEMBLER METHODS     
        // #########################################################################################

        /// <summary>
        /// PRE: NONE
        /// POST: Function call to the newline function located in helper.inc
        /// </summary>
        public void WRLN() { procedureStrings[currentProcedure] += "call\tnwln\r\n"; } // WRLN

        /// <summary>
        /// PRE: NONE
        /// POST: Code emitted to clear the screen
        /// </summary>
        public void CLS() { procedureStrings[currentProcedure] += "cls\r\n"; } // CLS

        // #########################################################################################
        // FILE HANDLER METHODS   FILE HANDLER METHODS   FILE HANDLER METHODS   FILE HANDLER METHODS   
        // #########################################################################################

        /// <summary>
        /// PRE:  The parse is complete.
        ///    c_iMainMemoryUse stores the amount of memory needed by the main procedure.
        /// POST: A string is created and the assembler "shell" is written to it.
        /// </summary>
        public string MainAFile()
        {
            // create a time stamp
            DateTime dt = DateTime.Now;

            string stringTemp = "; " + fm.COMPILER + " output for: " + fm.SOURCE_FILE + "\r\n"
                + "; Created: " + dt.ToString("F") + "\r\n\r\n"

                + "; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\r\n"
                + "\tinclude " + fm.MASM_DIR + "include\\masm32rt.inc\r\n"
                + "; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\r\n\r\n"

                + ".stack 1000H\r\n\r\n"    // plenty of stack space: 4096 bytes

                + ".data\r\n"   // begin DATA section
                + "\tinclude " + fm.SOURCE_NAME + "_strings.inc\t; all string literals\r\n"
                + "\r\n"
                + ".code\r\n"   // begin CODE section
                + "\tinclude " + fm.SOURCE_NAME + "_procs.inc\t; all program procedures\r\n"
                + "\tinclude helper.inc\t; includes some helper functions for printing and debugging\r\n"
                + "\r\n"

                + "start:\r\n\r\n"
                + "\tcls\r\n"
                + "\tsub\tESP," + string.Format("{0}", mainMemUse) + "\t; Room for main proc local vars\r\n"
                + "\tcall " + fm.MAIN_PROC + "\r\n"
                + "\tinkey\r\n"
                + "\texit\r\n\r\n"
                
                + "end start";

            return stringTemp;

        } // MainAFile

        /// <summary>
        /// PRE:  The name of the procedure is passed. We have already called 
        ///    EnterNewProcScope which tracks the current scope number. Note that this
        ///    array of procedure strings must remain parallel to the array of procedures
        ///    maintained by SymbolTable.
        /// POST: The preamble is emitted. This includes creating the assembly string
        ///    and increasing the procedure index.
        ///    
        /// Note the special version for the main procedure
        /// </summary>
        public void ProcPreamble(string strProcName)
        {
            // create the initial three lines of every procedure
            string stringTemp = "\r\n;============== BEGIN PROCEDURE ============\r\n"
                + strProcName + " PROC\t; Procedure definition\r\n"
                + "\tpush\tEBP\t; save EBP since we use it \r\n"
                + "\tmov\tEBP,ESP\r\n"
                + ";~~~~~~~~~~~~~ PREAMBLE END ~~~~~~~~~~~~~~~~\r\n";

            // add this string to the array of procedure strings
            procedureStrings.Add(stringTemp);

            // point to this newly-added fasm (file) string
            currentProcedure = SymbolTable.CUR_SCOPE;

        } // ProcPreamble

        /// <summary>
        /// 
        /// </summary>
        public void MainProcPreamble()
        { ProcPreamble(fm.MAIN_PROC); } // MainProcPreamble

        /// <summary>
        /// PRE:  The name of the procedure and 
        ///    the amount of memory needed in the stack is passed.
        ///    SymbolTable.ExitProcScope() has been called to re-establish 
        ///    the correct new scope.
        /// POST: The postamble is emitted to the current string.
        ///    The procedure index is returned to the correct value
        ///    (by querying SymbolTable).
        ///    
        /// Note the special version for the main procedure.
        /// </summary>
        public void ProcPostamble(string strProcName, int iMemUse)
        {
            procedureStrings[currentProcedure] += ";~~~~~~~~~~~~~ POSTAMBLE BEGIN ~~~~~~~~~~~~~\r\n"
                + "\tmov\tESP,EBP\r\n"
                + "\tpop\tEBP\r\n"
                + "\tret\t" + string.Format("{0}", iMemUse) + "\r\n"
                + strProcName + " endp\r\n"
                + ";=============== END PROCEDURE =============";

            // restore the correct scope
            currentProcedure = SymbolTable.CUR_SCOPE;

        } // ProcPostamble

        /// <summary>
        /// PRE:  The amount of memory needed in the stack is passed.
        ///    SymbolTable.ExitProcScope() has been called to re-establish 
        ///    the correct new scope.
        /// POST: The postamble is emitted to the current string.
        ///    The procedure index is returned to the correct value
        ///    (by querying SymbolTable). 
        ///    
        ///    Since this is the end of main (parsing is complete),
        ///    we now know the amount of memory needed by the main procedure.
        ///    We retain this for use while writing the outermost assembler file.
        /// </summary>
        public void MainProcPostamble(int iMemUse)
        { ProcPostamble(fm.MAIN_PROC, (mainMemUse = iMemUse)); } // MainProcPostamble

        /// <summary>
        /// PRE:  The assembler files have all been "written" to strings.
        /// POST: The files are written to the disk.
        /// </summary>
        public void WriteAllFiles()
        {
            // write the outermost "shell" assembler file
            fm.FileAFile(MainAFile(), fm.SOURCE_NAME + ".asm");

            // Create proclist.inc and write it. All the procedures will be written to a single file
            //    named "proclist.inc".
            string strProcInc = "; These are all the procedures for " + fm.SOURCE_FILE + ". Main is first.\r\n";

            foreach (string strProc in procedureStrings)
                strProcInc += strProc + "\r\n";

            // write the string of all procedures to the proper file
            fm.FileAFile(fm.PROC_LIST = strProcInc, fm.SOURCE_NAME + "_procs.inc");

            // write the string of strings to the proper file
            fm.FileAFile(fm.STRING_CONSTANTS = stringConstants, fm.SOURCE_NAME + "_strings.inc");

            // Create the Helper include file
            BuildHelperInclude();

            // Create the command file and invoke it to complete the assembly
            BuildBatFile();

            // Create the run file that will call the created exe file
            BuildRunFile();

        } // WriteAFiles

        /// <summary>
        /// PRE:  The parse is complete.
        /// POST: The command file is created for remaining steps of the assembly process
        ///    (compilation and linking to create an execcutable).
        ///    This command file is then run to complete the compilation.
        /// </summary>
        void BuildBatFile()
        {
            string strMakeFile =
                "@echo off\r\n\r\n"
                
                + "\tColor B\r\n\r\n" // hex color code idea from Mark Yanagihara-Brooks 2007
                // 0=white, 1=very dark blue, 2=dark green, 3=dark turquoise, 4= dark red, 5=dark purple, 6=olive,  7=white, 
                // 8=grey,  9=dark blue,      A=green,      B=neat turquoise, C=red,       D=purple,      E=yellow. F=white

                // set the assembly directory
                + "\tcd " + fm.ASM_DIR + "\r\n"
                
                + "\tif exist " + fm.SOURCE_NAME + ".obj del " + fm.SOURCE_NAME + ".obj\r\n"
                + "\tif exist " + fm.SOURCE_NAME + ".exe del " + fm.SOURCE_NAME + ".exe\r\n\r\n"

                // copy source mod file to assembly directory
                + "\tif not exist " + fm.SOURCE_FILE + " copy " + fm.SOURCE_DIR + fm.SOURCE_FILE + "\r\n\r\n"

                // change to root drive
                + "\tcd C:\\\r\n"
                + "\tC:\r\n\r\n"

                // make an assembly directory on the root drive and copy all needed files
                + "\tif exist C:\\CompilerOutput rmdir CompilerOutput /s /q\r\n"
                + "\tmkdir CompilerOutput\r\n\r\n"
                + "\tcd CompilerOutput\r\n\r\n"
                + "\tcopy " + fm.ASM_DIR + "\r\n\r\n"

                // assemble to create the object file
                + "\t" + fm.MASM_DIR + "bin\\ml /c /coff " + fm.SOURCE_NAME + ".asm\r\n"
                + "\tif errorlevel 1 goto errasm\r\n\r\n"

                // link the files to create the executable
                + "\t" + fm.MASM_DIR + "bin\\polink /SUBSYSTEM:CONSOLE " + fm.SOURCE_NAME + ".obj\r\n"
                + "\tif errorlevel 1 goto errlink\r\n\r\n"
				
				// copy all files back to ASM_DIR and remove temp root directory
				+ "\tcd " + fm.ASM_DIR + "\r\n"
                + "\t" + fm.ASM_DIR[0] + ":\r\n"
                + "\tcopy C:\\CompilerOutput\\" + fm.SOURCE_NAME + ".exe\r\n"
                + "\trmdir C:\\CompilerOutput /s /q\r\n\r\n"
                
				// show folder contents and then go to the end
                + "\tdir\r\n"
				+ "\tgoto TheEnd\r\n\r\n"

				// error on linking
                + ":errlink\r\n"
                + "\techo _\r\n"
                + "\techo Link Error\r\n"
                + "\tgoto TheEnd\r\n\r\n"

				// error on assembling
                + ":errasm\r\n"
                + "\techo _\r\n"
                + "\techo Assembly Error\r\n"
                + "\tgoto TheEnd\r\n\r\n"

				// successful program
                + ":TheEnd\r\n"
                + "\tpause\r\n"
                + "\tcls\r\n\r\n"

                + "@echo on";

            // Write the command string to the proper file.
            fm.FileAFile(strMakeFile, "!" + fm.SOURCE_NAME + ".bat");

            // Invoke the file just created. This uses the static method in our SystemCommand class.
            //    If an error occurs it will throw the appropriate exception. 
            //    TODO try and catch such an exception
            SystemCommand.SysCommand(fm.ASM_DIR + "!" + fm.SOURCE_NAME + ".bat");

        } // BuildBatFile

        /// <summary>
        /// 
        /// </summary>
        void BuildRunFile()
        {
            string strRunFile = "Color B\r\n\r\n"
                // hex color code idea from Mark Yanagihara-Brooks 2007
                // 0=white, 1=very dark blue, 2=dark green, 3=dark turquoise, 4= dark red, 5=dark purple, 6=olive,  7=white, 
                // 8=grey,  9=dark blue,      A=green,      B=neat turquoise, C=red,       D=purple,      E=yellow. F=white

                // set the assembly directory
                + "cd " + fm.ASM_DIR + "\r\n\r\n"

                + fm.SOURCE_NAME + ".exe";

            // Write the run string to the proper file.
            fm.FileAFile(strRunFile, "!RUN.cmd");

        } // BuildRunFile

        /// <summary>
        /// PRE:    None
        /// POST:   The helper file is created.
        /// </summary>
        private void BuildHelperInclude()
        {
            string strHelper =
            "; This must be included in the code segment.\r\n\r\n"

            + "nwln proc\r\n"
            + "\tprint chr$(13,10)\r\n"
            + "\tret\r\n"
            + "nwln endp";

            fm.FileAFile(strHelper, "helper.inc");

        } // BuildHelperInclude


    } // Emitter Class

} // Compiler Namespace