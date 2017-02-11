namespace Compiler.Forms
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.mainMenuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.programToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.testErrorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Get_A_Char_Button = new System.Windows.Forms.Button();
            this.List_Tokens_Button = new System.Windows.Forms.Button();
            this.Parse_Assemble_Button = new System.Windows.Forms.Button();
            this.Test_Symbols_Button = new System.Windows.Forms.Button();
            this.Run_Button = new System.Windows.Forms.Button();
            this.MASM_Directory_Textbox = new System.Windows.Forms.TextBox();
            this.Source_Directory_Textbox = new System.Windows.Forms.TextBox();
            this.Source_Directory_Browse_Button = new System.Windows.Forms.Button();
            this.Source_File_Textbox = new System.Windows.Forms.TextBox();
            this.Source_File_Browse_Button = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.MASM_Directory_Browse_Button = new System.Windows.Forms.Button();
            this.sourceDirectoryPicker = new System.Windows.Forms.FolderBrowserDialog();
            this.masmDirectoryPicker = new System.Windows.Forms.FolderBrowserDialog();
            this.mainMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // mainMenuStrip
            // 
            this.mainMenuStrip.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.mainMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.programToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.mainMenuStrip.Location = new System.Drawing.Point(0, 0);
            this.mainMenuStrip.Name = "mainMenuStrip";
            this.mainMenuStrip.Size = new System.Drawing.Size(684, 24);
            this.mainMenuStrip.TabIndex = 0;
            this.mainMenuStrip.Text = "Main Menu Strip";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(42, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Q)));
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(141, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.Exit);
            // 
            // programToolStripMenuItem
            // 
            this.programToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.testErrorToolStripMenuItem});
            this.programToolStripMenuItem.Name = "programToolStripMenuItem";
            this.programToolStripMenuItem.Size = new System.Drawing.Size(72, 20);
            this.programToolStripMenuItem.Text = "Program";
            // 
            // testErrorToolStripMenuItem
            // 
            this.testErrorToolStripMenuItem.Name = "testErrorToolStripMenuItem";
            this.testErrorToolStripMenuItem.Size = new System.Drawing.Size(135, 22);
            this.testErrorToolStripMenuItem.Text = "Test Error";
            this.testErrorToolStripMenuItem.Click += new System.EventHandler(this.TestError);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(49, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("aboutToolStripMenuItem.Image")));
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(111, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.About);
            // 
            // Get_A_Char_Button
            // 
            this.Get_A_Char_Button.Location = new System.Drawing.Point(26, 188);
            this.Get_A_Char_Button.Name = "Get_A_Char_Button";
            this.Get_A_Char_Button.Size = new System.Drawing.Size(122, 23);
            this.Get_A_Char_Button.TabIndex = 1;
            this.Get_A_Char_Button.Text = "Get a Char";
            this.Get_A_Char_Button.UseVisualStyleBackColor = true;
            this.Get_A_Char_Button.Click += new System.EventHandler(this.Get_A_Char_Button_Click);
            // 
            // List_Tokens_Button
            // 
            this.List_Tokens_Button.Location = new System.Drawing.Point(154, 188);
            this.List_Tokens_Button.Name = "List_Tokens_Button";
            this.List_Tokens_Button.Size = new System.Drawing.Size(122, 23);
            this.List_Tokens_Button.TabIndex = 3;
            this.List_Tokens_Button.Text = "List Tokens";
            this.List_Tokens_Button.UseVisualStyleBackColor = true;
            this.List_Tokens_Button.Click += new System.EventHandler(this.List_Tokens_Button_Click);
            // 
            // Parse_Assemble_Button
            // 
            this.Parse_Assemble_Button.Enabled = false;
            this.Parse_Assemble_Button.Location = new System.Drawing.Point(410, 188);
            this.Parse_Assemble_Button.Name = "Parse_Assemble_Button";
            this.Parse_Assemble_Button.Size = new System.Drawing.Size(122, 23);
            this.Parse_Assemble_Button.TabIndex = 5;
            this.Parse_Assemble_Button.Text = "Parse/Assemble";
            this.Parse_Assemble_Button.UseVisualStyleBackColor = true;
            // 
            // Test_Symbols_Button
            // 
            this.Test_Symbols_Button.Location = new System.Drawing.Point(282, 188);
            this.Test_Symbols_Button.Name = "Test_Symbols_Button";
            this.Test_Symbols_Button.Size = new System.Drawing.Size(122, 23);
            this.Test_Symbols_Button.TabIndex = 6;
            this.Test_Symbols_Button.Text = "Test Symbols";
            this.Test_Symbols_Button.UseVisualStyleBackColor = true;
            this.Test_Symbols_Button.Click += new System.EventHandler(this.Test_Symbols_Button_Click);
            // 
            // Run_Button
            // 
            this.Run_Button.Enabled = false;
            this.Run_Button.Location = new System.Drawing.Point(538, 188);
            this.Run_Button.Name = "Run_Button";
            this.Run_Button.Size = new System.Drawing.Size(122, 23);
            this.Run_Button.TabIndex = 7;
            this.Run_Button.Text = "Run";
            this.Run_Button.UseVisualStyleBackColor = true;
            // 
            // MASM_Directory_Textbox
            // 
            this.MASM_Directory_Textbox.Enabled = false;
            this.MASM_Directory_Textbox.Location = new System.Drawing.Point(177, 52);
            this.MASM_Directory_Textbox.Name = "MASM_Directory_Textbox";
            this.MASM_Directory_Textbox.Size = new System.Drawing.Size(369, 22);
            this.MASM_Directory_Textbox.TabIndex = 9;
            // 
            // Source_Directory_Textbox
            // 
            this.Source_Directory_Textbox.Enabled = false;
            this.Source_Directory_Textbox.Location = new System.Drawing.Point(177, 91);
            this.Source_Directory_Textbox.Name = "Source_Directory_Textbox";
            this.Source_Directory_Textbox.Size = new System.Drawing.Size(369, 22);
            this.Source_Directory_Textbox.TabIndex = 11;
            // 
            // Source_Directory_Browse_Button
            // 
            this.Source_Directory_Browse_Button.Location = new System.Drawing.Point(567, 91);
            this.Source_Directory_Browse_Button.Name = "Source_Directory_Browse_Button";
            this.Source_Directory_Browse_Button.Size = new System.Drawing.Size(75, 23);
            this.Source_Directory_Browse_Button.TabIndex = 10;
            this.Source_Directory_Browse_Button.Text = "Browse";
            this.Source_Directory_Browse_Button.UseVisualStyleBackColor = true;
            this.Source_Directory_Browse_Button.Click += new System.EventHandler(this.Source_Directory_Browse_Button_Click);
            // 
            // Source_File_Textbox
            // 
            this.Source_File_Textbox.Enabled = false;
            this.Source_File_Textbox.Location = new System.Drawing.Point(177, 131);
            this.Source_File_Textbox.Name = "Source_File_Textbox";
            this.Source_File_Textbox.Size = new System.Drawing.Size(369, 22);
            this.Source_File_Textbox.TabIndex = 13;
            // 
            // Source_File_Browse_Button
            // 
            this.Source_File_Browse_Button.Location = new System.Drawing.Point(567, 131);
            this.Source_File_Browse_Button.Name = "Source_File_Browse_Button";
            this.Source_File_Browse_Button.Size = new System.Drawing.Size(75, 23);
            this.Source_File_Browse_Button.TabIndex = 12;
            this.Source_File_Browse_Button.Text = "Browse";
            this.Source_File_Browse_Button.UseVisualStyleBackColor = true;
            this.Source_File_Browse_Button.Click += new System.EventHandler(this.Source_File_Browse_Button_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(40, 52);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(128, 20);
            this.label1.TabIndex = 14;
            this.label1.Text = "MASM Directory:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(40, 91);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(131, 20);
            this.label2.TabIndex = 15;
            this.label2.Text = "Source Directory:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(40, 131);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(93, 20);
            this.label3.TabIndex = 16;
            this.label3.Text = "Source File:";
            // 
            // MASM_Directory_Browse_Button
            // 
            this.MASM_Directory_Browse_Button.Location = new System.Drawing.Point(567, 52);
            this.MASM_Directory_Browse_Button.Name = "MASM_Directory_Browse_Button";
            this.MASM_Directory_Browse_Button.Size = new System.Drawing.Size(75, 23);
            this.MASM_Directory_Browse_Button.TabIndex = 17;
            this.MASM_Directory_Browse_Button.Text = "Browse";
            this.MASM_Directory_Browse_Button.UseVisualStyleBackColor = true;
            this.MASM_Directory_Browse_Button.Click += new System.EventHandler(this.MASM_Directory_Browse_Button_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 261);
            this.Controls.Add(this.MASM_Directory_Browse_Button);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Source_File_Textbox);
            this.Controls.Add(this.Source_File_Browse_Button);
            this.Controls.Add(this.Source_Directory_Textbox);
            this.Controls.Add(this.Source_Directory_Browse_Button);
            this.Controls.Add(this.MASM_Directory_Textbox);
            this.Controls.Add(this.Run_Button);
            this.Controls.Add(this.Test_Symbols_Button);
            this.Controls.Add(this.Parse_Assemble_Button);
            this.Controls.Add(this.List_Tokens_Button);
            this.Controls.Add(this.Get_A_Char_Button);
            this.Controls.Add(this.mainMenuStrip);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.mainMenuStrip;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximumSize = new System.Drawing.Size(700, 300);
            this.MinimumSize = new System.Drawing.Size(700, 300);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CompilerName";
            this.mainMenuStrip.ResumeLayout(false);
            this.mainMenuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip mainMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem programToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem testErrorToolStripMenuItem;
        private System.Windows.Forms.Button Get_A_Char_Button;
        private System.Windows.Forms.Button List_Tokens_Button;
        private System.Windows.Forms.Button Parse_Assemble_Button;
        private System.Windows.Forms.Button Test_Symbols_Button;
        private System.Windows.Forms.Button Run_Button;
        private System.Windows.Forms.TextBox MASM_Directory_Textbox;
        private System.Windows.Forms.TextBox Source_Directory_Textbox;
        private System.Windows.Forms.Button Source_Directory_Browse_Button;
        private System.Windows.Forms.TextBox Source_File_Textbox;
        private System.Windows.Forms.Button Source_File_Browse_Button;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button MASM_Directory_Browse_Button;
        private System.Windows.Forms.FolderBrowserDialog sourceDirectoryPicker;
        private System.Windows.Forms.FolderBrowserDialog masmDirectoryPicker;
    }
}