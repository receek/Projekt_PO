   M S B A M L   `   `   `  ����D  @ProjektPO, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:ProjektPO	ProjektPO  5          ProjektPO.RGB   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      )localclr-namespace:ProjektPO     5        N� Title$	  RGB��5	      .��5      � 
����  � � ColumnDefinitions 5   
   �� 5      �� 5      �� 5      �� 5       � RowDefinitions 5   
   �� 5      $��5* �6   �� 5      $��3* �6   �� 5      $��3* �6   �� 5      $��3* �6   .+�5   
   �� $	��100(�6   
���  ��$��0��64   $��0��6A   $��3��6Q   $��
RGB Module��6e   $��Impact)�6w    �� TextAlignment$ Center=�6�   $��0,10,0,0q�6�   �� 5   
   $��10q�6   $��0��6   $��3��6*   $��90��6:   $	��Top=�6F   $��7q�6^   
����� �._�5      �� -   5        $��Switch��5      $��22(�6#   $��Check state
 of the lamp��62   6Z   5      �� 5   
   $��2��6   $��10q�6%   $��1��61   $��0��6>   $��7q�6N   
����� �._�5      �  5       �� 5!      �� 5"      .+�5$      �� $��22(�6   
�������$��Last measured
value:��6=   $ Center=�6_   �� 5%      -   5        $��Actual��5%      $
��10,0q�6*   $��2��68   $��Center=�6H   $��28(�6c   
�������$ Center=�6�   $
��NONE��6�   5&      5'      �� 5(   
   $��10q�6   $��2��6   $��0��6*   $��7q�6;   
����� �._�5)      �� -   5        $��18(�5)      $��Click to Measure��6$   6?   5*      �� 5+   
   $��10q�6   $��2��6   $��1��6*   $��7q�6:   
����� �._�5,      �� -   5        $��SaveIntensity��5,      $��18(�6*   $��Click to save result��69   6X   5-      �� 5.   
   $��10q�6   $��2��6   $��3��61   $��0��6>   $��7q�6N   
����� �._�5/      �  50      �� 51      �� 52      .+�54      �� 
�������$��24(�6/   $��Center=�6=   $��State of Lamp:��6X   $ Center=�6o   �� 55      -   5        $��	LampState��55   /   
�������$��Center=�6@   $��1��6[   $��24(�6k   $��Unknown��6z   $ Center=�6�   56      57      �� 59   
   $��10q�6   $��1��6   $��2��6*   $��7q�6:   $��4��6N   
����� �._�5:      �  5;      �� 5<      $��2* �6$   �� 5=      $��1* �6$   �� 5>      $��5* �6$    5@      �� 5A      �� 5B      �� 5C      .+�5E      �� -   5        $��3��5E      $��18(�6-   $��Set new color��6<   6T   �� 5F      $��Center=�6   $��16(�69   
�������$��1��6Z   $	��RED��6g   �� 5G      $��Center=�6   $��16(�69   
�������$��1��6Z   $��1��6g   $��GREEN��6w   �� 5H      $��Center=�6   $��16(�69   
�������$��1��6Z   $��2��6g   $
��BLUE��6w   �� 5I      -   5        $��	RedSlider��5I   3    � Minimum$ 1Q�6    � Maximum$	 255Q�6%   $��0,0,0,10q�6D    �� Orientation$ Vertical=�6V   $��2��6m   $��Center=�6z   �� 5J      -   5        $��GreenSlider��5J   3   $ 1Q�6   $	 255Q�6%   $��1��6F   $��0,0,0,10q�6V   $ Vertical=�6h   $��2��6   $��Center=�6�   �� 5K      -	   5        $��
BlueSlider��5K   3   $ 1Q�6   $	 255Q�6%   $��2��6E   $��0,0,0,10q�6U   $ Vertical=�6g   $��2��6~   $��Center=�6�   5L      5M      �� 5O   
   $��10q�6   $��0��6    $��2��6-   $��2��6=   $��Bottom=�6R   $��Right=�6m   $ Right=�6�   
������ 
�������$��20(�6�   $��List of noted measures:��6�   �� 5P   
   $��7q�6   
����� �$��10q�6<   $��3��6Q   $��1��6a   $��4��6n   $��1��6   ._�5Q      �� -
   5        $
��Dane��5Q   /   
������ $��20(�6;   5R      5S      5T      