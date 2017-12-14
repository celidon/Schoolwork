/*
	File Name: Appointment.java
    Developer: Anthony Hansen
    Date Last Modified: 04.05.2014
    Description: The assignment was to declare an interface Filter as follows:
						public interface Filter
						{
							boolean accept(Object x);
						}
				Write a method:
						public static ArrayList<Object> collectAll(ArrayList<Object> objects, Filter f)
				that returns all objects in the objects array that are accepted
				by the given filter. Provide a class ShortWordFilter whose filter
				method accepts all strings of length < 5. Then write a program
				that reads all words from System.in, puts them into an ArrayList<Object>,
				calls collectAll, and prints a list of the short words.
	Email Address: hansen.tony92@gmail.com
*/

import java.util.*;

public class ShortWordFilter
{
	public static interface Filter
	{
		boolean accept(Object x);
	}
	public static class ShortWord implements Filter
	{
	public boolean accept(Object x)
	{
		String y=x.toString();
		
		if(y.length()<5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	}
	
	
	public static ArrayList<Object> collectAll(ArrayList<Object> objects, Filter f)
	{
		ArrayList<Object> temp=new ArrayList<Object>();
		
		for(Object x:objects)
		{
			if(f.accept(x))
			{
				temp.add(x);
			}
		}
		
		return temp;
	}
	
	public static Scanner in=new Scanner(System.in);

	public static void main(String[] args)
	{
		ArrayList<Object> originalList=new ArrayList<Object>();
		
		String x;
		System.out.println("Please enter a block of text. 00000 ends text reading:\n");
		do{
			x=in.next();
			Object z=(Object)x;
			originalList.add(z);
		}while(!x.equals("00000"));
		
		for(Object y:collectAll(originalList,new ShortWord()))
		{
			System.out.println(y);
		}
		
	}
}