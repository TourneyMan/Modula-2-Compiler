using System;
using System.Diagnostics;
using System.ComponentModel;    // to handle Win32 file access errors

namespace Compiler
{
    /// <summary>
    /// SystemCommand is a singleton class that lets us run commands on the local
    ///    system. The idea and about half the command code is from:
    ///    http://msdn2.microsoft.com/en-us/library/system.diagnostics.process.aspx
    /// </summary>
    class SystemCommand
    {
        /// <summary>
        /// Instead of a constructor, we offer a static method to run a command.
        /// </summary>
        private SystemCommand() { } // private constructor so no one else can create one.

        /// <summary>
        /// SysCommand executes the given string on the local system.
        ///    If an error is detected false is returned, otherwise true.
        /// </summary>
        public static bool SysCommand(string command)
        {
            // Track defaults and file locations.
            FileManager fm = FileManager.Instance;

            // These are the Win32 error codes for these two specific errors.
            const int ERROR_FILE_NOT_FOUND = 2;
            const int ERROR_ACCESS_DENIED = 5;

            System.Diagnostics.Process process = new Process();
            process.StartInfo.RedirectStandardOutput = false;
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.FileName = command;
            process.StartInfo.UseShellExecute = true;
            
            try // attempt to run the command:
            {
                process.Start();
                process.WaitForExit();
                process.Dispose();
            }
            catch (Win32Exception ex)
            {
                // check for known errors first
                if (ex.NativeErrorCode == ERROR_FILE_NOT_FOUND)
                {
                    ErrorHandler.Error(ERROR_CODE.UKNOWN_ERROR,
                                       "System Command",
                                       string.Format(ex.Message + ". Check the path ('" + command + "')."));

                    return false;
                }
                else if (ex.NativeErrorCode == ERROR_ACCESS_DENIED)
                {
                    ErrorHandler.Error(ERROR_CODE.UKNOWN_ERROR,
                                       "System Command",
                                       string.Format(ex.Message + ". You do not have permission to execute this file ('" + command + "')."));
                    
                    return false;
                }

                // unknown error - just report
                ErrorHandler.Error(ERROR_CODE.UKNOWN_ERROR,
                                       "System Command",
                                       string.Format(ex.Message + " ('" + command + "')."));

                return false;
            }

            return true; // all must be well

        } // SysCommand

    } // SystemCommand Class

} // Compiler Namespace