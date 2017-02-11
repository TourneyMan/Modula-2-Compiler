using System;
using System.Windows.Forms;

namespace Compiler.Forms
{
    public partial class MainForm : Form
    {
        // Track defaults and file locations.
        private FileManager fm = FileManager.Instance;
        Facade facade = new Facade();

        /// <summary>
        /// class constructor
        /// </summary>
        public MainForm()
        {
            InitializeComponent();

            // The file manager holds the name of the project
            Text = fm.COMPILER;
            MASM_Directory_Textbox.Text = fm.MASM_DIR;
            Source_Directory_Textbox.Text = fm.SOURCE_DIR;
            Source_File_Textbox.Text = fm.SOURCE_FILE;


        } // MainForm

        /// <summary>
        /// Test the error handler
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TestError(object sender, EventArgs e)
        {
            ErrorHandler.Error(ERROR_CODE.NONE, "Main Form", "Test Error");
            fm.FileErrorLog();

        } // TestError

        /// <summary>
        /// Display information about the compiler program
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void About(object sender, EventArgs e)
        { new AboutForm().ShowDialog(); } // About

        /// <summary>
        /// Exit the program
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Exit(object sender, EventArgs e)
        {
            // clean up this form and dispose of it
            Close();
            Dispose();

        } // Exit

        /// <summary>
        /// Open a form to pick a folder for MASM source. Set matching textbox and corresponding variable in the FileManager
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MASM_Directory_Browse_Button_Click(object sender, EventArgs e)
        {
            if (masmDirectoryPicker.ShowDialog() == DialogResult.OK) //If the chosen folder is good
            {
                MASM_Directory_Textbox.Text = masmDirectoryPicker.SelectedPath; //Set the textbox text
                fm.MASM_DIR = MASM_Directory_Textbox.Text; //Change FileManager var
            }
        }

        /// <summary>
        /// Open a form to pick a folder for the Source Directory. Set matching textbox and corresponding variable in the FileManager
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Source_Directory_Browse_Button_Click(object sender, EventArgs e)
        {
            if (sourceDirectoryPicker.ShowDialog() == DialogResult.OK)
            {
                Source_Directory_Textbox.Text = sourceDirectoryPicker.SelectedPath;
                fm.SOURCE_DIR = Source_Directory_Textbox.Text;
            }
        }

        /// <summary>
        /// Choose a file from the Source Directory. Set matching textbox and corresponding variable in the FileManager
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Source_File_Browse_Button_Click(object sender, EventArgs e)
        {
            OpenFileDialog sourceFilePicker = new OpenFileDialog();
            sourceFilePicker.InitialDirectory = fm.SOURCE_DIR; //Set the initial directory

            if (sourceFilePicker.ShowDialog() == DialogResult.OK)
            {
                Source_File_Textbox.Text = System.IO.Path.GetFileName(sourceFilePicker.FileName);
                fm.SOURCE_FILE = Source_File_Textbox.Text;
            }
        }

        /// <summary>
        /// Open up a form that can parse through the chosen .mod file
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Get_A_Char_Button_Click(object sender, EventArgs e)
        {
            GetChar getACharForm = new Forms.GetChar();

            try {getACharForm.Show();}
            catch (Exception excep) {}
            
            //Get_A_Char_Button.Enabled = true;
        }

        /// <summary>
        /// Lexes through the chosen .mod file and displays a .txt file showing a list of the Tokens in the file
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void List_Tokens_Button_Click(object sender, EventArgs e)
        {
            new SourceReader(); //Prepare the SourceReader
            
            facade.ListTokens();
            SystemCommand.SysCommand((fm.SOURCE_DIR + fm.SOURCE_FILE).Replace(".mod", "") + "_" + fm.COMPILER + "\\" + (fm.SOURCE_FILE + "_Tokens.txt").Replace(".mod", "")); //Open the file
        }

        private void Test_Symbols_Button_Click(object sender, EventArgs e)
        {
            Filer.CreateCleanDir(fm.SOURCE_DIR + "TestSym_" + fm.COMPILER);
            facade.TestSymTable();
            SystemCommand.SysCommand(fm.SOURCE_DIR + "TestSym_" + fm.COMPILER + "\\" + ("Test_Symbols.txt")); //Open the file

        }
    } // MainForm class

} // Compiler.Forms namespace