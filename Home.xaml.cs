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
    /// Logika interakcji dla klasy Strona1.xaml
    /// </summary>
    public partial class Home : Page
    {
        MainWindow Rodzic;
        DostepneModuly dostepne = new DostepneModuly();
        Czujnik_Temperatury czujnik_Temperatury = new Czujnik_Temperatury();
        public bool Connection = false;
        public bool loadedModules = false;
        public bool choosenModules = false;

        public Home(MainWindow x)
        {
            InitializeComponent();
            PODSTRONA.Content = dostepne;
            Rodzic = x;
        }

        public bool CheckConnection()
        {
            return true;
        }

        private void CheckConnectionButtonClick(object sender, RoutedEventArgs e){
            Connection = CheckConnection();//COkolwiek XD
            if (Connection == true)
                Connected.Text = "Connected";
            else
                Connected.Text = "Disconnected";
        }

        private void LoadModulesButtonClick(object sender, RoutedEventArgs e){
            if (!loadedModules){
                loadedModules = true;
                LoadModules();
            }            
        }

        public int ConvertFromName(){
            return 1;
        }

        private void ChooseModulesButtonClick(object sender, RoutedEventArgs e){
            if (choosenModules)
                return;
            choosenModules = true;
            string[] nazwy;
            int ile = 0;
            foreach( CheckBox b in dostepne.listBox1.Items)
                if(b.IsChecked == true)
                    ile++;
            nazwy = new string[ile];
            int it = 0;
            foreach (CheckBox b in dostepne.listBox1.Items)
                if (b.IsChecked == true)
                    nazwy[it++] = (string)b.Content;
            Rodzic.Tablica = new Nadklasa[ile];
            Console.WriteLine(ile);
            System.Console.WriteLine("ZARAZ");
            for (int i = 0; i < ile; i++){
                System.Console.WriteLine(nazwy[i] + "OK");
                if(nazwy[i] == "CZT")
                    Rodzic.Tablica[i] = new KlasaCzujnikaTemperatury();
                if(nazwy[i] == "BUZ")
                    Rodzic.Tablica[i] = new KlasaBuzzer();
                if(nazwy[i] == "RGB")
                    Rodzic.Tablica[i] = new KlasaRGB();
                if(nazwy[i] == "WIL")
                    Rodzic.Tablica[i] = new KlasaCzujnikaWilgotnosci();
                if(nazwy[i] == "ODL")
                    Rodzic.Tablica[i] = new KlasaCzujnikaOdleglosci();
                if (nazwy[i] == "LAM")
                    Rodzic.Tablica[i] = new KlasaLampki();
                Button x = new Button();
                x.Tag = i;
                x.Content = nazwy[i] + i.ToString();
                x.Name = nazwy[i] + i.ToString();
                x.Click += Rodzic.B_Click;
                Rodzic.LISTBOX.Items.Add(x);
            }
        }

        public void LoadModules()
        {
            int ile_dostalem_itemkow = 7;
            string[] itemki = new string[ile_dostalem_itemkow];//Przykladowe moduly Jakie od Cb dostane
            itemki[0] = "CZT";
            itemki[1] = "BUZ";
            itemki[2] = "LAM";
            itemki[3] = "WIL";
            itemki[4] = "RGB";
            itemki[5] = "CZT";
            itemki[6] = "ODL";

            for(int i = 0; i < ile_dostalem_itemkow; i++){
                CheckBox temp = new CheckBox();
                temp.Content = itemki[i];
                dostepne.listBox1.Items.Add(temp);
            }
        }

    }
}
