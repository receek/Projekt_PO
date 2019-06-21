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
    /// Logika interakcji dla klasy RGB.xaml
    /// </summary>
    public partial class RGB : Page
    {
        bool saved = false;
        Home Rodzic;
        int idTab;
        int idMod;
        int count = 0;
        //bool check = false;
        Dictionary<string, string> POM = new Dictionary<string, string>();

        public RGB(int IDTAB, int IDMOD, Home Ro)
        {
            InitializeComponent();
            idTab = IDTAB;
            idMod = IDMOD;
            Rodzic = Ro;
            //Actual.BackColor = Color.
            //Label x = new Label();
            //x.Background = (System.Windows.Media.Brush)"Green";
        }

        private void SaveRGB_Click(object sender, RoutedEventArgs e)
        {
            string p = Actual.Text;
            if (p == "NONE")
            {
                MessageBox.Show("You Have not measured a thing yet");
                return;
            }
            if (saved)
            {
                MessageBox.Show("You are trying to save the same result twice");
                return;
            }
            saved = true;
            //TextBlock kolorek = new TextBlock();
            //string w = "#" + POM[(Convert.ToInt32(Nadklasa.slowo(Actual.Text, 1)) / 16).ToString()] + POM[(Convert.ToInt32(Nadklasa.slowo(Actual.Text, 2)) / 16).ToString()] + POM[(Convert.ToInt32(Nadklasa.slowo(Actual.Text + "\n", 3)) / 16).ToString()];
            //Console.WriteLine(w);
            //kolorek.Background = new SolidColorBrush(Color.FromArgb()(0, 0xFF, 0, 0)); ; 
            TextBlock pom = new TextBlock();
            pom.Text = Actual.Text;
            pom.Background = Actual.Background;
            pom.FontSize = 24;
            pom.Foreground = new SolidColorBrush(Colors.White);
            pom.MinWidth = 140;
            Dane.Items.Add(pom);
        }

        private void GetRGB_Click(object sender, RoutedEventArgs e)
        {
            saved = false;
            count++;
            string p = Rodzic.Rodzic.Tablica[idTab].AskRGB(idMod);
            //Console.WriteLine(p);
            //Console.WriteLine(Nadklasa.slowo(p, 1) + Nadklasa.slowo(p, 2) + Nadklasa.slowo(p, 3));
            Actual.Text = Nadklasa.slowo(p,1) + " " + Nadklasa.slowo(p,2) + " " + Nadklasa.slowo(p,3);
            //Console.WriteLine(Nadklasa.slowo(p, 1));
            //Console.WriteLine(Nadklasa.slowo(p, 2));
            //Console.WriteLine(Nadklasa.slowo(p, 3));
            byte R = Convert.ToByte(Nadklasa.slowo(p, 1));
            byte G = Convert.ToByte(Nadklasa.slowo(p, 2));
            byte B = Convert.ToByte(Nadklasa.slowo(p, 3));
            Actual.Background = new SolidColorBrush(Color.FromArgb(255, R, G, B));
        }

        private void SetRGB_Click(object sender, RoutedEventArgs e)
        {
            saved = false;
            count++;
            string R = Convert.ToInt32(RedSlider.Value).ToString();
            string G = Convert.ToInt32(GreenSlider.Value).ToString();
            string B = Convert.ToInt32(BlueSlider.Value).ToString();
            Rodzic.Rodzic.Tablica[idTab].SetRGB(idMod, R.ToString() + " " + G.ToString() + " " + B.ToString() );
        }

        private void Switch_Click(object sender, RoutedEventArgs e)
        {
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
                string pom = Rodzic.Rodzic.Tablica[idTab].AskRGB(idMod);
                Console.WriteLine(pom);

                pom = Nadklasa.slowo(pom,4);

                if (pom == "OFF")
                {
                    Switch.Content = "Switch ON\n RGB lamp";
                    LampState.Text = "OFF";
                }
                else
                {
                    Switch.Content = "Switch OFF\n RGB lamp";
                    LampState.Text = "ON";
                }
                return;
            }
            if (LampState.Text == "OFF")
            {
                //Console.WriteLine("Wlaczam");
                string x = Rodzic.Rodzic.Tablica[idTab].SwitchRGBON(idMod);
                if (x == "OK\n")
                {
                    Switch.Content = "Switch OFF\n RGB lamp";
                    LampState.Text = "ON";
                }
                else
                    MessageBox.Show("Unexpected problem trying to switch the RGB on");
            }
            else
            {
                string x = Rodzic.Rodzic.Tablica[idTab].SwitchRGBOFF(idMod);
                if (x == "OK\n")
                {
                    LampState.Text = "OFF";
                    Switch.Content = "Switch ON\n RGB lamp";
                }
                else
                    MessageBox.Show("Unexpected problem trying to switch the RGB off");
            }
        }
    }
}
