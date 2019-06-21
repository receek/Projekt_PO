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
    public class KlasaCzujnikaWilgotnosci : Nadklasa{
        public KlasaCzujnikaWilgotnosci(int idTab, int idMod, Home home){
            Klatka.Content = new Czujnik_Wilgotnosci(idTab, idMod, home);
        }
        public override string AskHumidity(int id)
        {
            return SendMessage("VAL " + id.ToString() + "\n");
        }
    }
}
