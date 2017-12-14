/*
   File Name: NumberAdder.java
   Developer: Anthony Hansen
   Date Last Modified: 09.04.2014
   Description: The assignment was to write a program that asks the user to input
				a set of floating-point values. When the user enters a value that
				is not a number, give the user a second chance to enter the value.
				After two chances, quit reading input. Add all correctly specified
				values and print the sum when the user is done entering data. Use
				exception handling to detect improper inputs.
Email Address: hansen.tony92@gmail.com
*/

import java.util.*;

public class NumberAdder {

	public static Scanner in=new Scanner(System.in);
	
	public static Float input()
	{
		try
		{
			System.out.println("Please insert a number: ");
			return in.nextFloat();
		}
		catch(Exception e)
		{
			System.out.println("Not a number. Try again");
			return null;
		}
	}
	
	public static void main(String[] args) {
	
		float sum=0;
		Float number;
		int attempt=0;
		
		do{
			number=input();
			if(number==null)
			{
				attempt++;
				in=new Scanner(System.in);
			}
			else
			{
				sum+=number;
				attempt=0;
			}
			
		}while(attempt!=2);
		
		System.out.println("The sum of the entered numbers is: "+sum);
	
	}
}