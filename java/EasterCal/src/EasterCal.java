/*
   File Name: HelloWorld.java
   Developer: Anthony Hansen
   Date Last Modified: 13.02.2014
   Description: The assignment was to write a program that prompts the user
                for a year and prints out the month and day of Easter Sunday.
Email Address: hansen.tony92@gmail.com
*/

//import java.util.Scanner;
import javax.swing.JOptionPane;

public class EasterCal {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Scanner in = new Scanner(System.in);
		
		//System.out.print("Please input a year: ");
		//int y= in.nextInt();
		String input = JOptionPane.showInputDialog("Please input a year: ");
		//Algorithm taken from book
		int y= Integer.parseInt(input);
		int a = y%19;
		int b = y/100;
		int c = y%100;
		int d = b/4;
		int e = b%4;
		int g = (8*b + 13)/25;
		int h = (19*a + b - d - g + 15)%30;
		int j = c/4;
		int k = c%4;
		int m = (a+11*h)/319;
		int r = (2*e + 2*j - k - h + m + 32)%7;
		int n = (h - m + r + 90)/25;
		int p = (h - m + r + n + 19)%32;
		
		/*System.out.print("In ");
		System.out.print(y);
		System.out.print(", Easter happens on ");
		System.out.print(n);
		System.out.print("/");
		System.out.print(p);*/
		
		JOptionPane.showMessageDialog(null, "In " + y + ", Easter happens on " + n + "/" + p );
	}

}
