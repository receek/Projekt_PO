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
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary> 

    public partial class MainWindow : Window{
        Home HomeWindow;
        public Nadklasa[] Tablica;
        public MainWindow(){
            InitializeComponent();
            HomeWindow = new Home(this);
            MAIN.Content = HomeWindow;
        }

        private void A_Click(object sender, RoutedEventArgs e){
            MAIN.Content = HomeWindow;
        }

        public void B_Click(object sender, RoutedEventArgs e)
        {
            System.Console.WriteLine("ELDON");
            Button x = (Button)sender;
            MAIN.Content = Tablica[(int)x.Tag].Klatka.Content;
        }
    }
}
