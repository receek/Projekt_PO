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
    public class KlasaLampki : Nadklasa{
        public KlasaLampki(int idTab, int idMod, Home h){
            Klatka.Content = new Lampka(idTab, idMod, h);
        }
        public override string SwitchLampkaOFF(int x)
        {
            //string wyslany = "COM " + x.ToString() + " STP\n";
            return SendMessage("COM " + x.ToString() + " STP\n");
        }
        public override string SwitchLampkaON(int x)
        {
            //string wyslany = "COM " + x.ToString() + " STR\n";
            //Console.WriteLine(wyslany);
            return SendMessage("COM " + x.ToString() + " STR\n");
        }
        public override string AskIntensity(int x)
        {
            return SendMessage("VAL " + x.ToString() + "\n");
        }
        public override bool IsON(int x)
        {
            //string pom = SendMessage("VAL " + x.ToString() + "\n");
            return slowo(SendMessage("VAL " + x.ToString() + "\n"),2) == "ON";
        }
    }
}
