using System;
using System.IO;                // FileStream, Directory, etc.
using System.Windows.Forms;     // MessageBox
using System.Data;              // DataTable
using System.Text;              // StringBuilder

namespace Compiler
{
    class Filer
    {
        /// <summary>
        /// Default constructor
        /// </summary>
        private Filer() { }

        /// <summary>
        /// This creates and/or clears a directory with the given name
        /// </summary>
        /// <param name="directory"></param>
        public static void CreateCleanDir(string directory)
        {
            // delete the directory and all its contents if it exists
            if (Directory.Exists(directory))
                Directory.Delete(directory, true); // "true" means delete recursively

            // Create the directory
            Directory.CreateDirectory(directory);

        } // CreateCleanDir

        /// <summary>
        /// Write the contents of a string to the file specified
        /// PRE:    A string and file name with path is provided
        /// POST:   True is returnd if write was successfull
        /// </summary>
        /// <param name="contents"></param>
        /// <param name="path"></param>
        /// <returns></returns>
        public static bool WriteStringToFile(string contents, string path)
        {
            FileManager fm = FileManager.Instance;

            FileStream fOut;

            // check to see if we have a valid file name
            if (path.Length < 3)
            {

                string message = String.Format("Failed to open file. File name is '{0}.", path);
                ErrorHandler.Error(ERROR_CODE.FILE_OPEN_ERROR, "Filer - WriteStringToFile", message);

                return false;
            }

            // open the output file
            try
            {
                fOut = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.Write);
            }
            catch (Exception e)
            {
                string message = String.Format("Failed to open '{0}' with exception {1}", path, e.Message);
                ErrorHandler.Error(ERROR_CODE.FILE_OPEN_ERROR, "Filer - WriteStringToFile", message);

                return false;
            }

            // http://www.joelonsoftware.com/articles/Unicode.html Good article about unicode.
            // Finally we actually write the string to the file!
            // We use a StreamWriter to do the decoding from Unicode to UTF8
            //        StreamWriter swout = new StreamWriter (fout, Encoding.UTF8, BUFFER_SIZE);
            StreamWriter swOut = new StreamWriter(fOut);
            swOut.Write(contents);
            swOut.Flush();
            swOut.Close();

            return true;

        } // WriteStringToFile

    } // Filer Class
    
} // Compiler Namespace