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
    public class KlasaRGB : Nadklasa{
        public KlasaRGB(int idTab, int idMod, Home h)
        {
            Klatka.Content = new RGB(idTab, idMod, h);
        }
        public override string SwitchRGBOFF(int x)
        {
            string wyslany = "COM " + x.ToString() + " STP\n";
            return SendMessage(wyslany);
        }
        public override string SwitchRGBON(int x)
        {
            string wyslany = "COM " + x.ToString() + " STR\n";
            return SendMessage(wyslany);
        }
        public override string AskRGB(int x)
        {
            return SendMessage("VAL " + x.ToString() + "\n");
        }
        public override bool IsON(int x)
        {
            string pom = SendMessage("VAL " + x.ToString() + "\n");
            //Console.WriteLine(pom);
            return slowo(pom, 4) == "ON";
        }
        public override void SetRGB(int x, string y)
        {
            string p = SendMessage("COM " + x.ToString() + " CHN " + y + "\n");

            if(slowo(p,1) != "OK")
            {
                MessageBox.Show("Unexpected Error");
            }
        }
    }
}
