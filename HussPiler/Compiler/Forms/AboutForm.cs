using System;
using System.Reflection;
using System.Windows.Forms;

namespace Compiler.Forms
{
    partial class AboutForm : Form
    {
        FileManager fm = FileManager.Instance;

        /// <summary>
        /// Initialize form
        /// </summary>
        public AboutForm()
        {
            InitializeComponent();

            // reference to the executing assembly
            Assembly app = Assembly.GetExecutingAssembly();

            // get assembly info in useable chunks
            AssemblyCopyrightAttribute copyright = (AssemblyCopyrightAttribute)app.GetCustomAttributes(typeof(AssemblyCopyrightAttribute), false)[0];
            AssemblyCompanyAttribute company = (AssemblyCompanyAttribute)app.GetCustomAttributes(typeof(AssemblyCompanyAttribute), false)[0];
            AssemblyDescriptionAttribute description = (AssemblyDescriptionAttribute)app.GetCustomAttributes(typeof(AssemblyDescriptionAttribute), false)[0];
            Version verTemp = Version.Parse(ProductVersion);

            // format version number for user disply
            String strVersion = verTemp.Major + "." + verTemp.Minor + "." + verTemp.Build % 100;

            Text = String.Format("About {0}", fm.COMPILER);
            lblProductName.Text = fm.COMPILER;
            lblVersion.Text = String.Format("Version {0}", strVersion);
            lblCopyright.Text = copyright.Copyright.ToString();
            lblCompanyName.Text = company.Company.ToString();
            tbDescription.Text = description.Description.ToString();
            
        } // AboutForm
        
    } // AboutForm class

} // Compiler.Forms namespace