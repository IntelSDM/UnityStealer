using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using UnityEngine;
namespace Payload
{
    class GameInfo
    {
        public GameInfo()
        {
            SetGame();
        }
        void SetGame()
        {
            // could call getfilename and pass null but this just seems acceptable

            Name = System.Diagnostics.Process.GetCurrentProcess().ProcessName;
            ProcessTarget = Name + ".exe";

            File.WriteAllText("test.txt", Name);
            File.WriteAllText("test2.txt", ProcessTarget);
        }
        private string Name;
        private string ProcessTarget;
    }
}
