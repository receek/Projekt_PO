﻿#pragma checksum "..\..\RGB.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "F8A6F7FAABCDE7A53474388510ABA87F02047243"
//------------------------------------------------------------------------------
// <auto-generated>
//     Ten kod został wygenerowany przez narzędzie.
//     Wersja wykonawcza:4.0.30319.42000
//
//     Zmiany w tym pliku mogą spowodować nieprawidłowe zachowanie i zostaną utracone, jeśli
//     kod zostanie ponownie wygenerowany.
// </auto-generated>
//------------------------------------------------------------------------------

using ProjektPO;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace ProjektPO {
    
    
    /// <summary>
    /// RGB
    /// </summary>
    public partial class RGB : System.Windows.Controls.Page, System.Windows.Markup.IComponentConnector {
        
        
        #line 28 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button Switch;
        
        #line default
        #line hidden
        
        
        #line 37 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBlock Actual;
        
        #line default
        #line hidden
        
        
        #line 44 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button SaveIntensity;
        
        #line default
        #line hidden
        
        
        #line 53 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBlock LampState;
        
        #line default
        #line hidden
        
        
        #line 73 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Slider RedSlider;
        
        #line default
        #line hidden
        
        
        #line 74 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Slider GreenSlider;
        
        #line default
        #line hidden
        
        
        #line 75 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Slider BlueSlider;
        
        #line default
        #line hidden
        
        
        #line 81 "..\..\RGB.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ListBox Dane;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/ProjektPO;component/rgb.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\RGB.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.Switch = ((System.Windows.Controls.Button)(target));
            
            #line 28 "..\..\RGB.xaml"
            this.Switch.Click += new System.Windows.RoutedEventHandler(this.Switch_Click);
            
            #line default
            #line hidden
            return;
            case 2:
            this.Actual = ((System.Windows.Controls.TextBlock)(target));
            return;
            case 3:
            
            #line 41 "..\..\RGB.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.GetRGB_Click);
            
            #line default
            #line hidden
            return;
            case 4:
            this.SaveIntensity = ((System.Windows.Controls.Button)(target));
            
            #line 44 "..\..\RGB.xaml"
            this.SaveIntensity.Click += new System.Windows.RoutedEventHandler(this.SaveRGB_Click);
            
            #line default
            #line hidden
            return;
            case 5:
            this.LampState = ((System.Windows.Controls.TextBlock)(target));
            return;
            case 6:
            
            #line 69 "..\..\RGB.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.SetRGB_Click);
            
            #line default
            #line hidden
            return;
            case 7:
            this.RedSlider = ((System.Windows.Controls.Slider)(target));
            return;
            case 8:
            this.GreenSlider = ((System.Windows.Controls.Slider)(target));
            return;
            case 9:
            this.BlueSlider = ((System.Windows.Controls.Slider)(target));
            return;
            case 10:
            this.Dane = ((System.Windows.Controls.ListBox)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}

