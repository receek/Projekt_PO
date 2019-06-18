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
using System.Net;
using System.Net.Sockets;

namespace ProjektPO
{
    /// <summary>
    /// Logika interakcji dla klasy Strona1.xaml
    /// </summary>
    public partial class Home : Page
    {
        MainWindow Rodzic;
        DostepneModuly dostepne = new DostepneModuly();
        Czujnik_Temperatury czujnik_Temperatury = new Czujnik_Temperatury();
        Dictionary<string, string> map = new Dictionary<string, string>();
        Dictionary<string, int> map2 = new Dictionary<string, int>();
        public bool Connection = false;
        public bool loadedModules = false;
        public bool choosenModules = false;
        Nadklasa ST = new Nadklasa();
        public Home(MainWindow x)
        {
            InitializeComponent();
            Rodzic = x;
            map["RGB"] = "RGB";
            map["CZT"] = "Temperature";
            map["CZO"] = "Distance";
            map["CZW"] = "Humidity";
            map["LAM"] = "Light";
            map["BUZ"] = "Buzzer";
            map2["RGB\nModule"] = map2["Distance\nModule"] = map2["Temperature\nModule"] = map2["Humidity\nModule"]  = map2["Light\nModule"] = map2["Buzzer\nModule"] = 0;
        }

        public bool CheckConnection(){
            string adresIP = IP.Text;
            string port = Port.Text;

            if (!Nadklasa.Init(adresIP, port))
                return false;
            Console.WriteLine(Nadklasa.SendMessage("HLL\n"));
            return true;
        }

        private void CheckConnectionButtonClick(object sender, RoutedEventArgs e){
            //---Playground mode ---
            Connection = true;
            ConnectedText.Text = "Connected";
            return;
            //-------------------
            Connection = CheckConnection();
            if (Connection == true)
                ConnectedText.Text = "Connected";
            else
                ConnectedText.Text = "Disconnected";
        }

        private void LoadDataButtonClick(object sender, RoutedEventArgs e){
            if (!Connection)
            {
                MessageBox.Show("You have to be connected to load modules");
                return;
            }
            if (!loadedModules){
                loadedModules = true;
                PODSTRONA.Content = dostepne;
                DataText.Text = "Loaded";
                LoadModules();
            }            
            else
                MessageBox.Show("You can only load modules once");

        }

        public int ConvertFromName(){
            return 1;
        }

        private void ChooseModulesButtonClick(object sender, RoutedEventArgs e){
            if (!loadedModules){
                MessageBox.Show("First you need to load modules");
                return;
            }
            if (choosenModules){
                MessageBox.Show("You can only choose modules once");
                return;
            }
            string[] nazwy;
            int ile = 0;
            foreach( CheckBox b in dostepne.listBox1.Items)
                if(b.IsChecked == true)
                    ile++;
            nazwy = new string[ile];
            int it = 0;
            foreach (CheckBox b in dostepne.listBox1.Items)
                if (b.IsChecked == true)
                    nazwy[it++] = (string)b.Content+ "\nModule";
            Rodzic.Tablica = new Nadklasa[ile];
            Console.WriteLine(ile);
            for (int i = 0; i < ile; i++){
                if(nazwy[i] == "Temperature\nModule")
                    Rodzic.Tablica[i] = new KlasaCzujnikaTemperatury();
                if(nazwy[i] == "Buzzer\nModule")
                    Rodzic.Tablica[i] = new KlasaBuzzer();
                if(nazwy[i] == "RGB\nModule")
                    Rodzic.Tablica[i] = new KlasaRGB();
                if(nazwy[i] == "Humidity\nModule")
                    Rodzic.Tablica[i] = new KlasaCzujnikaWilgotnosci();
                if(nazwy[i] == "Distance\nModule")
                    Rodzic.Tablica[i] = new KlasaCzujnikaOdleglosci();
                if(nazwy[i] == "Light\nModule")
                    Rodzic.Tablica[i] = new KlasaLampki();
                Button x = new Button();
                x.Tag = i;
                x.Content = nazwy[i];
                map2[nazwy[i]] += 1;
                if(map2[nazwy[i]] > 1)
                    x.Content += "(" + map2[nazwy[i]] + ")";
                x.Click += Rodzic.B_Click;
                x.HorizontalAlignment = HorizontalAlignment.Center;
                x.FontSize = 14;
                Rodzic.LISTBOX.Items.Add(x);
            }
            if(ile == 0)
            {
                MessageBox.Show("You have not choose any modules");
                return;
            }
            choosenModules = true;
            ModulesText.Text = "Choosen";
            MessageBox.Show("You have succesfully selected " + ile + " modules that you can navigate now");
        }

        public int wyluskaj(string x){
            int dl = 0;
            while(x[dl] != '\n')
                dl++;
            return dl;
        }

        public void LoadModules(){
            //-------Playground Mode--------
            CheckBox t = new CheckBox();
            t.Content = "RGB";
            dostepne.listBox1.Items.Add(t);
            t = new CheckBox();
            t.Content = "Buzzer";
            dostepne.listBox1.Items.Add(t);
            t = new CheckBox();
            t.Content = "Humidity";
            dostepne.listBox1.Items.Add(t);
            t = new CheckBox();
            t.Content = "Temperature";
            dostepne.listBox1.Items.Add(t);
            t = new CheckBox();
            t.Content = "Distance";
            dostepne.listBox1.Items.Add(t);
            t = new CheckBox();
            t.Content = "Light";
            dostepne.listBox1.Items.Add(t);
            t = new CheckBox();
            t.Content = "Light";
            dostepne.listBox1.Items.Add(t);
            return;
            //------------------------------
           
            string modolki = Nadklasa.SendMessage("ASK\n");
            int dl = wyluskaj(modolki);
            int val = Convert.ToInt32(modolki.Substring(0, dl));
            for(int i = 0; i < val; i++){
                string nazwa = map[modolki.Substring(dl + 1 + 4 * i, 3)];
                CheckBox temp = new CheckBox();
                temp.Content = nazwa;
                dostepne.listBox1.Items.Add(temp);
            }
        }
    }
}
