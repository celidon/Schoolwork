/*
   File Name: SyllableCounter.java
   Developer: Anthony Hansen
   Date Last Modified: 08.03.2014
   Description: The assignment was to write a program that reads a word and
				prints the number of syllables in the word. For this exercise,
				assume that syllables are determined as follows: Each sequence
				of adjacent vowels a e i o u y, except for the last e in a word,
				is a syllable. However, if that algorithm yields a count of 0,
				change it to 1
Email Address: hansen.tony92@gmail.com
*/

import java.util.Scanner;

public class SyllableCounter
{	
	public static void main(String[] args)
	{	

		Scanner in = new Scanner(System.in);
		
		int syllables=0;
		int i=0;
		System.out.print("Please enter a word: \n");
		String input=in.nextLine();
		
		while(i<(input.length()-1))
		{
			if(input.charAt(i)=='a'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='e'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='i'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='o'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='u'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='y'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else
			{
				i++;
			}
			
		}
		while(i==(input.length()-1))
		{
			if(input.charAt(i)=='a'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='i'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='o'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='u'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else if(input.charAt(i)=='y'&&(input.charAt(i-1)!='a'&&input.charAt(i-1)!='e'&&input.charAt(i-1)!='i'&&input.charAt(i-1)!='o'&&input.charAt(i-1)!='u'&&input.charAt(i-1)!='y'))
			{
				syllables++;
				i++;
			}
			else
			{
				i++;
			}
		}
		if(syllables==0)
		{
			syllables=1;
		}
		System.out.println(input+" has "+syllables+" syllables");
	}
}