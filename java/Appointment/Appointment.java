/*
	File Name: Appointment.java
    Developer: Anthony Hansen
    Date Last Modified: 04.05.2014
    Description: The assignment was to implement a superclass Appointment and
				 subclasses Onetime, Daily, and Monthly. An appointment has a
				 description (for example, “see the dentist”) and a date. Write
				 a method occursOn(int year, int month, int day) that checks
				 whether the appointment occurs on that date. For example, for
				 a monthly appointment, you must check whether the day of the 
				 month matches. Then fill an array of Appointment objects with
				 a mixture of appointments. Have the user enter a date and print
				 out all appointments that occur on that date.
	Email Address: hansen.tony92@gmail.com
*/

import java.util.*;

public class Appointment
{	
	public static Scanner in=new Scanner(System.in);
	
	void occursOn(int d,int m,int y)
	{
		System.out.println("Appointment:");
	}

	public static class Daily extends Appointment
	{
		int day,month,year;
		String description;
		
		public Daily(int d, int m, int y, String des)
		{
			day=d;
			month=m;
			year=y;
			description=des;
		}
		
		void occursOn(int dateDay, int dateMonth, int dateYear)
		{
			if(dateDay>=day&&(dateMonth>=month||dateYear>=year))
			{
				System.out.println(description);
			}
		}
	}
	
	public static class Monthly extends Appointment
	{
		int day,month,year;
		String description;
		
		public Monthly(int d, int m, int y, String des)
		{
			day=d;
			month=m;
			year=y;
			description=des;
		}
		
		void occursOn(int dateDay, int dateMonth, int dateYear)
		{
			if(dateDay==day&&(dateMonth>=month||dateYear>=year))
			{
				System.out.println(description);
			}
		}
	}
	
	public static class Yearly extends Appointment
	{
		int day,month,year;
		String description;
		
		public Yearly(int d, int m, int y, String des)
		{
			day=d;
			month=m;
			year=y;
			description=des;
		}
		
		void occursOn(int dateDay, int dateMonth, int dateYear)
		{
			if(dateDay==day&&dateMonth==month&&dateYear>=year)
			{
				System.out.println(description);
			}
		}
	}
	
	public static class Onetime extends Appointment
	{
		int day,month,year;
		String description;
		
		public Onetime(int d, int m, int y, String des)
		{
			day=d;
			month=m;
			year=y;
			description=des;
		}
		
		void occursOn(int dateDay, int dateMonth, int dateYear)
		{
			if(dateDay==day&&dateMonth==month&&dateYear==year)
			{
				System.out.println(description);
			}
		}
	}
	
	public static void main(String[] args)
	{
		int x,y,z;
		
		Daily dobj=new Daily(21,03,1992,"Life");
		Monthly mobj=new Monthly(26,06,2010,"Mensiversary");
		Yearly yobj=new Yearly(21,03,1992,"Birthday");
		Onetime oobj=new Onetime(2,05,2014,"This program works");
	
		Appointment[] appointments=new Appointment[]{dobj,mobj,yobj,oobj};
		
		do{
		System.out.println("Please enter a day: ");
		x=in.nextInt();
		System.out.println("Please enter a month: ");
		y=in.nextInt();
		System.out.println("Please enter a year: ");
		z=in.nextInt();
		if(x>=31||x<0)
		{
			System.out.println("Invalid day");
		}
		if(y>=12||y<0)
		{
			System.out.println("Invalid month");
		}
		}while(x>31||x<0||y<0||y>12);
		
		System.out.println("Appointments for "+y+"/"+x+"/"+z+" :");
		for(int i=0;i<appointments.length;i++)
		{
			appointments[i].occursOn(x,y,z);
		}
		
		do{
		System.out.println("Please enter a day: ");
		x=in.nextInt();
		System.out.println("Please enter a month: ");
		y=in.nextInt();
		System.out.println("Please enter a year: ");
		z=in.nextInt();
		if(x>31||x<0)
		{
			System.out.println("Invalid day");
		}
		if(y>12||y<0)
		{
			System.out.println("Invalid month");
		}
		}while(x>31||x<0||y<0||y>12);
		
		System.out.println("Appointments for "+y+"/"+x+"/"+z+" :");
		for(int i=0;i<appointments.length;i++)
		{
			appointments[i].occursOn(x,y,z);
		}
	}
}