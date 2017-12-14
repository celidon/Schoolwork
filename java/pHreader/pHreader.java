/*
   File Name: pHreader.java
   Developer: Anthony Hansen
   Date Last Modified: 24.02.2014
   Description: The assignment was to write a program that allows the user to
				input a pH value and output whether the solution is acidic,
				alkaline, or neutral.
Email Address: hansen.tony92@gmail.com
*/

import javax.swing.JOptionPane;

public class pHreader
{	
	public static void main(String[] args)
	{		
		String input = JOptionPane.showInputDialog("What is the pH?");
		
		double pH=Double.parseDouble(input);
		
		if(pH>=0 && pH<=14)
		{
			if(pH>=0 && pH<7)
			{
				JOptionPane.showMessageDialog(null, "It is acidic");
			}
			else if(pH>7 && pH<=14)
			{
				JOptionPane.showMessageDialog(null, "It is alkaline");
			}
			else if(pH==7)
			{
				JOptionPane.showMessageDialog(null, "It is neutral");
			}
		}
		else
		{
			JOptionPane.showMessageDialog(null, "Invalid pH");
		}
	}
}