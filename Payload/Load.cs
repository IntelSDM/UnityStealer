using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Payload
{
    public class Load
    {
        // drop in game directory
        // change game directory to 7days/7days
        // keep original which opens and then closes and opens the next 7 days
       
        public static void Init()
        {
            File.WriteAllText("test.txt","");
            GameInfo gameinfo = new GameInfo();
            

        }
    }
}
