using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ProjektPO{
    public class KlasaBuzzer : Nadklasa{
        public KlasaBuzzer(int IDTAB, int IDMOD, Home h)
        {
            Klatka.Content = new Buzzer(IDTAB, IDMOD, h);
        }
        public override string AskPower(int x)
        {
            return slowo(SendMessage("VAL " + x.ToString() + "\n"), 1);
        }
        public override void BuzzerON(int x)
        {
            SendMessage("COM " + x.ToString() + " STR\n");
        }
        public override void BuzzerOFF(int x)
        {
            SendMessage("COM " + x.ToString() + " STP\n");
        }
        public override void SetBuzzerPower(int x, string val)
        {
            SendMessage("COM " + x.ToString() + " CHN " + val + "\n");
        }
    }
}
