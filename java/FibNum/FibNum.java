/*
   File Name: FibNum.java
   Developer: Anthony Hansen
   Date Last Modified: 08.03.2014
   Description: The assignment was to write a program that prompts the user for
				an integer n and prints the nth Fibonacci number, using the
				algorithm:
				f1=1
				f2=1
				fn=f(n-1)+f(n-2) or 
				fnew=f1+f2, f2=f1, f1=fnew repeated for some i<n
Email Address: hansen.tony92@gmail.com
*/

import javax.swing.JOptionPane;

public class FibNum
{	
	public static void main(String[] args)
	{
		String input = JOptionPane.showInputDialog("Which Fibonacci number would you like to see?");
		
		int n = Integer.parseInt(input);
		
		int f1=1;
		int f2=1;
		int fnew;
		
		if(n<3)
		{
			JOptionPane.showMessageDialog(null, "The "+n+" Fibonacci number is 1");
		}
		else
		{
			//Set i to less than n-2 because the first two Fibonacci numbers were
			//already declared earlier and have their own outputs.		
			for(int i=0; i<n-2; i++)
			{
				fnew=f1+f2;
				f2=f1;
				f1=fnew;
			}
			JOptionPane.showMessageDialog(null, "The "+n+" Fibonacci number is "+f1);
		}
	}	
}