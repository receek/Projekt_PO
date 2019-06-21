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
using System.Collections.ObjectModel;
using System.Windows.Shapes;

namespace ProjektPO{
    public partial class Czujnik_Temperatury : Page{
        bool saved = false;
        Home Rodzic;
        int idTab;
        int idMod;
        int count = 0;
        public Czujnik_Temperatury(int IDTAB, int IDMOD, Home Ro){
            InitializeComponent();
            idTab = IDTAB;
            idMod = IDMOD;
            Rodzic = Ro;
        }

        private void SaveTemperature_Click(object sender, RoutedEventArgs e){
            string p = Actual.Text;
            if(p == "NONE"){
                MessageBox.Show("You Have not measured a thing yet");
                return;
            }
            if (saved){
                MessageBox.Show("You are trying to save the same result twice");
                return;
            }
            saved = true;
            Dane.Items.Add("Measure nr" + count.ToString() + ": " + p + " C");
        }

        private void GetTemperature_Click(object sender, RoutedEventArgs e){
            saved = false;
            count++;
            string p = Rodzic.Rodzic.Tablica[idTab].AskTemperature(idMod);
            Actual.Text = Nadklasa.slowo(p, 1);
        }
    }
}
