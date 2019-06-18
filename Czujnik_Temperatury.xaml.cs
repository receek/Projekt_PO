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

namespace ProjektPO
{
    /// <summary>
    /// Logika interakcji dla klasy Strona2.xaml
    /// </summary>
    public partial class Czujnik_Temperatury : Page
    {
        Home Rodzic;
        int Address;
        //DostepneModuly dostepne = new DostepneModuly();
        //public ObservableCollection<BoolStringClass> myItemList { get; set; }
        public Czujnik_Temperatury(Home x, int y)
        {
            InitializeComponent();
            Rodzic = x;
            Address = x;
        }

        public Update()

    }
}
