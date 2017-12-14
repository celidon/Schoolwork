/*
   File Name: UnitConverter.java
   Developer: Anthony Hansen
   Date Last Modified: 24.02.2014
   Description: The assignment was to write a program that allows the user to
				convert from certain units(fl oz, gal, oz, lbs, in, ft, mi) to
				others(ml, l, g, kg, mm, cm, m, km).
Email Address: hansen.tony92@gmail.com
*/

import javax.swing.JOptionPane;

public class UnitConverter
{	
	public static void main(String[] args)
	{
		double conversion;
		
		JOptionPane.showMessageDialog(null, "Please enter the units in their abbreviated forms without punctuation.");
	
		String from = JOptionPane.showInputDialog("From what units would you like to convert?\n(fl oz, gal, oz, lbs, in, ft, mi)");
		
		String to = JOptionPane.showInputDialog("To what would units you like to convert?\n(ml, l, g, kg, mm, cm, m, km)");
		
		String input = JOptionPane.showInputDialog("How many of the first units would you like to convert?");
		
		double num=Double.parseDouble(input);
		
		if(from.equalsIgnoreCase("in"))
		{
			if(to.equalsIgnoreCase("mm"))
			{
				conversion=num*25.4;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("cm"))
			{
				conversion=num*2.54;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("m"))
			{
				conversion=num*.0254;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("km"))
			{
				conversion=num*.00254;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		else if(from.equalsIgnoreCase("ft"))
		{
			if(to.equalsIgnoreCase("mm"))
			{
				conversion=num*25.4*12;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("cm"))
			{
				conversion=num*2.54*12;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("m"))
			{
				conversion=num*.0254*12;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("km"))
			{
				conversion=num*.00254*12;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		else if(from.equalsIgnoreCase("mi"))
		{
			if(to.equalsIgnoreCase("mm"))
			{
				conversion=num*25.4*63360;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("cm"))
			{
				conversion=num*2.54*63360;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("m"))
			{
				conversion=num*.0254*63360;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("km"))
			{
				conversion=num*.00254*63360;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		else if(from.equalsIgnoreCase("fl oz"))
		{
			if(to.equalsIgnoreCase("ml"))
			{
				conversion=num*29.5735;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("l"))
			{
				conversion=num*.0295735;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		else if(from.equalsIgnoreCase("gal"))
		{
			if(to.equalsIgnoreCase("ml"))
			{
				conversion=num*29.5735*128;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("l"))
			{
				conversion=num*.0295735*128;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		else if(from.equalsIgnoreCase("oz"))
		{
			if(to.equalsIgnoreCase("g"))
			{
				conversion=num*28.3495;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("kg"))
			{
				conversion=num*.0283495;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		else if(from.equalsIgnoreCase("lbs"))
		{
			if(to.equalsIgnoreCase("g"))
			{
				conversion=num*28.3495*16;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else if(to.equalsIgnoreCase("kg"))
			{
				conversion=num*.0283495*16;
				JOptionPane.showMessageDialog(null, num+" "+from+" is "+conversion+" "+to);
			}
			else
			{
				JOptionPane.showMessageDialog(null, "Invalid conversion");
			}
		}
		
		JOptionPane.showMessageDialog(null, "Next time you should probably just use Google");
	}
}