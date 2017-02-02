using System;
using System.Windows.Forms;

namespace Compiler.Forms
{
    public partial class GetChar : Form
    {
        FileManager fm = FileManager.Instance;
        public GetChar()
        {
            InitializeComponent();
            
            Basic_Info_Label.Text = "The next character of " + fm.SOURCE_FILE + " is:"; //Set text for file chosen

            new SourceReader(); //Sets fm.SOURCE_READER
            if (fm.SOURCE_READER.Open()) { Get_Next_Button_Click(new object(), new EventArgs());/*DisplayNextChar();*/ }
            else
            {
                fm.SOURCE_READER.Close();
                this.Close();
            } //If the file can't be opened, close the form

        }

        /// <summary>
        /// Displays the next character of the file, going to the next line if needed. Skips blank lines.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Get_Next_Button_Click(object sender, EventArgs e)
        {
            String stringToShow = "";
            char charToShow = fm.SOURCE_READER.GetNextOneChar();
            if (charToShow == (char)255) { stringToShow = "EOF"; }
            else if (charToShow == ' ') { stringToShow = "SPACE"; }     //Converting characters to corresponding strings
            else if (charToShow == '\r') { stringToShow = "CARRIAGE RETURN";  }
            else { stringToShow = charToShow.ToString(); }
            Current_Char_Label.Text = "Line: " + fm.SOURCE_READER.LINE_NUMBER + " - " + stringToShow;
        }

        /// <summary>
        /// Pushes back the source reader to show the character directly before the one currently being displayed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Push_Back_Button_Click(object sender, EventArgs e)
        {
            fm.SOURCE_READER.PushBackOneChar();
            Get_Next_Button_Click(sender, e);
        }

        /// <summary>
        /// Cleans up variables and closes the Get a Char form
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Done_Button_Click(object sender, EventArgs e)
        {
            fm.SOURCE_READER.Close();
            this.Close();
        }

        /// <summary>
        /// Resets source reader to beginning of the file
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Reset_Button_Click(object sender, EventArgs e)
        {
            fm.SOURCE_READER.Reset();
            Get_Next_Button_Click(sender, e);
        }
    }
}
