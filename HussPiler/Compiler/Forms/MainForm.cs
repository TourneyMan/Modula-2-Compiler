using System;
using System.Windows.Forms;

namespace Compiler.Forms
{
    public partial class MainForm : Form
    {
        // Track defaults and file locations.
        private FileManager fm = FileManager.Instance;
        
        /// <summary>
        /// class constructor
        /// </summary>
        public MainForm()
        {
            InitializeComponent();

            // The file manager holds the name of the project
            Text = fm.COMPILER;
        
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

    } // MainForm class

} // Compiler.Forms namespace