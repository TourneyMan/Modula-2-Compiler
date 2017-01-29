namespace Compiler.Forms
{
    partial class GetChar
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
            this.Basic_Info_Label = new System.Windows.Forms.Label();
            this.Current_Char_Label = new System.Windows.Forms.Label();
            this.Push_Back_Button = new System.Windows.Forms.Button();
            this.Get_Next_Button = new System.Windows.Forms.Button();
            this.Reset_Button = new System.Windows.Forms.Button();
            this.Done_Button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Basic_Info_Label
            // 
            this.Basic_Info_Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Basic_Info_Label.Location = new System.Drawing.Point(12, 9);
            this.Basic_Info_Label.Name = "Basic_Info_Label";
            this.Basic_Info_Label.Size = new System.Drawing.Size(327, 34);
            this.Basic_Info_Label.TabIndex = 0;
            this.Basic_Info_Label.Text = "The next character of 01_Test.mod is:";
            this.Basic_Info_Label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Current_Char_Label
            // 
            this.Current_Char_Label.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Current_Char_Label.Location = new System.Drawing.Point(12, 43);
            this.Current_Char_Label.Name = "Current_Char_Label";
            this.Current_Char_Label.Size = new System.Drawing.Size(327, 23);
            this.Current_Char_Label.TabIndex = 1;
            this.Current_Char_Label.Text = "label1";
            this.Current_Char_Label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Push_Back_Button
            // 
            this.Push_Back_Button.Location = new System.Drawing.Point(98, 78);
            this.Push_Back_Button.Name = "Push_Back_Button";
            this.Push_Back_Button.Size = new System.Drawing.Size(75, 23);
            this.Push_Back_Button.TabIndex = 2;
            this.Push_Back_Button.Text = "Push Back";
            this.Push_Back_Button.UseVisualStyleBackColor = true;
            this.Push_Back_Button.Click += new System.EventHandler(this.Push_Back_Button_Click);
            // 
            // Get_Next_Button
            // 
            this.Get_Next_Button.Location = new System.Drawing.Point(13, 78);
            this.Get_Next_Button.Name = "Get_Next_Button";
            this.Get_Next_Button.Size = new System.Drawing.Size(75, 23);
            this.Get_Next_Button.TabIndex = 1;
            this.Get_Next_Button.Text = "Get Next";
            this.Get_Next_Button.UseVisualStyleBackColor = true;
            this.Get_Next_Button.Click += new System.EventHandler(this.Get_Next_Button_Click);
            // 
            // Reset_Button
            // 
            this.Reset_Button.Location = new System.Drawing.Point(265, 78);
            this.Reset_Button.Name = "Reset_Button";
            this.Reset_Button.Size = new System.Drawing.Size(75, 23);
            this.Reset_Button.TabIndex = 4;
            this.Reset_Button.Text = "Reset";
            this.Reset_Button.UseVisualStyleBackColor = true;
            this.Reset_Button.Click += new System.EventHandler(this.Reset_Button_Click);
            // 
            // Done_Button
            // 
            this.Done_Button.Location = new System.Drawing.Point(179, 78);
            this.Done_Button.Name = "Done_Button";
            this.Done_Button.Size = new System.Drawing.Size(75, 23);
            this.Done_Button.TabIndex = 5;
            this.Done_Button.Text = "Done";
            this.Done_Button.UseVisualStyleBackColor = true;
            this.Done_Button.Click += new System.EventHandler(this.Done_Button_Click);
            // 
            // GetChar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(351, 109);
            this.Controls.Add(this.Done_Button);
            this.Controls.Add(this.Reset_Button);
            this.Controls.Add(this.Get_Next_Button);
            this.Controls.Add(this.Push_Back_Button);
            this.Controls.Add(this.Current_Char_Label);
            this.Controls.Add(this.Basic_Info_Label);
            this.Name = "GetChar";
            this.Text = "HussPiler - Get a Char";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label Basic_Info_Label;
        private System.Windows.Forms.Label Current_Char_Label;
        private System.Windows.Forms.Button Push_Back_Button;
        private System.Windows.Forms.Button Get_Next_Button;
        private System.Windows.Forms.Button Reset_Button;
        private System.Windows.Forms.Button Done_Button;
    }
}