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
    public partial class Buzzer : Page
    {
        Home Rodzic;
        int idTab;
        int idMod;
        int count = 0;
        bool saved = false;
        public Buzzer(int IDTAB, int IDMOD, Home Ro)
        {
            InitializeComponent();
            idTab = IDTAB;
            idMod = IDMOD;
            Rodzic = Ro;
        }

        private void SavePower_Click(object sender, RoutedEventArgs e)
        {
            string p = Actual.Text;
            if (p == "NONE")
            {
                MessageBox.Show("You have not measured a thing yet");
                return;
            }
            if (saved)
            {
                MessageBox.Show("You are trying to save the same result twice");
                return;
            }
            saved = true;
            Dane.Items.Add("Measure nr" + count.ToString() + ": " + p + " Hz");
        }

        private void GetPower_Click(object sender, RoutedEventArgs e)
        {
            saved = false;
            count++;
            string p = Rodzic.Rodzic.Tablica[idTab].AskPower(idMod);
            Actual.Text = p;
        }

        private void TurnONBuzzer_Click(object sender, RoutedEventArgs e)
        {
            Rodzic.Rodzic.Tablica[idTab].BuzzerON(idMod);
        }

        private void SetBuzzerPower_Click(object sender, RoutedEventArgs e)
        {
            Console.WriteLine(Convert.ToInt32(Slider.Value));
            Rodzic.Rodzic.Tablica[idTab].SetBuzzerPower(idMod, Convert.ToInt32(Slider.Value).ToString());
        }

        private void TurnOFFBuzzer_Click(object sender, RoutedEventArgs e)
        {
            Rodzic.Rodzic.Tablica[idTab].BuzzerOFF(idMod);
        }
    }
}
