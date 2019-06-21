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

namespace ProjektPO
{
    /// <summary>
    /// Logika interakcji dla klasy Lampka.xaml
    /// </summary>
    public partial class Lampka : Page
    {
        bool saved = false;
        Home Rodzic;
        int idTab;
        int idMod;
        int count = 0;
        //bool check = false;
        public Lampka(int IDTAB, int IDMOD, Home Ro){
            InitializeComponent();
            idTab = IDTAB;
            idMod = IDMOD;
            Rodzic = Ro;
        }

        private void SaveIntensity_Click(object sender, RoutedEventArgs e){
            string p = Actual.Text;
            if (p == "NONE"){
                MessageBox.Show("You Have not measured a thing yet");
                return;
            }
            if (saved){
                MessageBox.Show("You are trying to save the same result twice");
                return;
            }
            saved = true;
            Console.WriteLine(p);
            Dane.Items.Add("Measure nr" + count.ToString() + ": " + Nadklasa.slowo(p, 1) + " lumens");
        }

        private void GetIntensity_Click(object sender, RoutedEventArgs e){
            saved = false;
            count++;
            string p = Nadklasa.slowo(Rodzic.Rodzic.Tablica[idTab].AskIntensity(idMod), 1);
            Actual.Text = p + " lm";
        }

        private void Switch_Click(object sender, RoutedEventArgs e){
            //-------playground mode -----------
            /*if (ON == false)
            {
                ON = true;
                Switch.Content = "Switch OFF";
            }
            else
            {
                ON = false;
                Switch.Content = "Switch ON";
            }
            return;*/
            //----------------------------------
            string q = (string)Switch.Content;
            if (q[0] == 'C')
            {
                string pom = Rodzic.Rodzic.Tablica[idTab].AskIntensity(idMod);
                pom = Nadklasa.slowo(pom, 2);
                if (pom == "OFF")
                {
                    Switch.Content = "Turn the\n lamp ON";
                    LampState.Text = "OFF";
                }
                else
                {
                    Switch.Content = "Turn the\n lamp OFF";
                    LampState.Text = "ON";
                }
                return;
            }
            if (LampState.Text == "OFF"){
                string x = Rodzic.Rodzic.Tablica[idTab].SwitchLampkaON(idMod);
                Console.WriteLine(x);
                if (x == "OK\n"){
                    Switch.Content = "Switch OFF";
                    LampState.Text = "ON";
                }
                else
                    MessageBox.Show("Unexpected problem trying to switch the sensor on");
            }
            else{
                string x = Rodzic.Rodzic.Tablica[idTab].SwitchLampkaOFF(idMod);
                Console.WriteLine(x);

                if (x == "OK\n"){
                    LampState.Text = "OFF";
                    Switch.Content = "Switch ON";
                }
                else
                    MessageBox.Show("Unexpected problem trying to switch the sensor off");
            }
        }
    }
}
