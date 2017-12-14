/*
   File Name: RomNum.java
   Developer: Anthony Hansen
   Date Last Modified: 13.03.2014
   Description: The assignment was to write a program that allows the user to
				input a number and then convert that number to roman numerals
				using a function multiple times.
Email Address: hansen.tony92@gmail.com
*/

import javax.swing.JOptionPane;

public class RomNum
{
	public static String Roman(int n, String one, String five, String ten)
	{
		String roman="";
		
		if(n%10!=0)
		{
			if(n%10<4)
			{
				for(int i=0; i<n%10;i++)
				{
					roman=roman+one;
				}				
			}
			else if(n%10==4)
			{
				roman=one+five;
			}
			else if(n%10>=5&&n%10<9)
			{
				roman=five;
				
				for(int i=0; i<(n%10-5); i++)
				{
					roman=roman+one;
				}
			}
			else if(n%10==9)
			{
				roman=one+ten;
			}
		}
		else
		{
			roman="";
		}
		
		return roman;
	}
	//Function for the output of anything larger than 999
	public static String Roman(int n, String thousand)
	{
		String roman="";
		
		for(int i=0; i<n;i++)
		{
			roman=roman+thousand;
		}
		
		return roman;
	}
	
	public static void main(String[] args)
	{		
		String input=JOptionPane.showInputDialog("Please enter a number to convert to Roman numerals:");
		int n=Integer.parseInt(input);
		int original=n;
		
		String end, middle, start, full;
		
		end=Roman(n,"I","V","X");
		
		n=n/10;
		
		middle=Roman(n,"X","L","C");
		
		n=n/10;
		
		start=Roman(n,"C","D","M");
		
		n=n/10;
		
		full=Roman(n,"M")+start+middle+end;
		
		JOptionPane.showMessageDialog(null, "Number: "+original+"\nRoman Numeral: "+full);
	}
}