   M S B A M L   `   `   `  ����D  @ProjektPO, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:ProjektPO	ProjektPO  5      #    ProjektPO.Czujnik_Temperatury   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      )localclr-namespace:ProjektPO     5        N� Title$  Strona2��5	      .��5      � 
���z��� � ColumnDefinitions 5   
   �� 5      �� 5      �� 5      �� 5       � RowDefinitions 5   
   �� 5      $��5* �6   �� 5      $��3* �6   �� 5      $��6* �6   .+�5   
   �� $��50(�6   
���  ��$��0��63   $��0��6@   $��3��6P   $��Temperature Module��6d   $��Yu Gothic UI Semibold)�6~    �� TextAlignment$ Center=�6�   $��0,10,0,0q�6�   �� 5   
   $��10q�6   $��1��6   $��0��6*   $��7q�6:   $��2��6N   ���#e00._�5      �  5      �� 5      �� 5      .+�5      �� $��22(�6   $��Last measured
value:��6'   $ Center=�6I   �� 5       -   5        $��Actual��5       $��1��6&   $��40(�66   
�������$ Center=�6W   $
��NONE��6n   5!      5"      �� 5#   
   $��10q�6   $��2��6   $��0��6*   $��7q�6;   ���#e00._�5$      �� -   5        $��GetTemperature��5$      
�������$��24(�6C   $��Click to
Measure��6R   6r   5%      �� 5&   
   $��10q�6   $��2��6   $��1��6*   $��7q�6:   ���#e00._�5'      �� -   5        $��SaveTemperature��5'      
�������$��24(�6C   $��Click to
save result��6R   6v   5(      �� 5)   
   $��10q�6   $��0��6    $��2��6-   $��2��6=   $
��Left=�6Q   $��Bottom=�6l   $
 Left=�6�   
������ $��27(�6�   $��List of noted measures:��6�   �� 5*   
   $��10q�6   ���#e00$��7q�61   $��2��6E   $��1��6U   $��3��6b   $��2��6s   ._�5+      �� -   5        $
��Dane��5+   /   
������ $��20(�6;   5,      5-      5.      