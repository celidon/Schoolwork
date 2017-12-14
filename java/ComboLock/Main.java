/*
   File Name: Main.java
   Developer: Anthony Hansen
   Date Last Modified: 16.04.2014
   Description: The assignment was to write a program that simulates a combination
				lock with a 3 number combination, a dial that goes between 0 and
				39, and functions to reset the lock, turn the dial both directions,
				and try to open the lock.
Email Address: hansen.tony92@gmail.com
*/

//This is the test function for the class ComboLock that was created to the 
//specifics listed in the description.
 
import java.util.*;
 
public class Main {

public static Scanner in=new Scanner(System.in);

public static void main(String[] args){ 
        
		int choice, ticks;
		
		System.out.print("Please insert the first number of the combination: ");
		int c1=in.nextInt();
		
		System.out.print("Please insert the second number of the combination: ");
		int c2=in.nextInt();
		
		System.out.print("Please insert the third number of the combination: ");
		int c3=in.nextInt();
		
		ComboLock lock1=new ComboLock(c1,c2,c3);
        
		do{
			System.out.println("What would you like to do: ");
			System.out.println("1 Reset lock");
			System.out.println("2 Turn lock right");
			System.out.println("3 Turn lock left");
			System.out.println("4 Attempt to open lock");
		    choice=in.nextInt();
			
			if(choice==1)
			{
				lock1.reset();
			}
			else if(choice==2)
			{
				System.out.println("How many ticks?");
				ticks=in.nextInt();
				lock1.turnRight(ticks);
			}
			else if(choice==3)
			{
				System.out.println("How many ticks?");
				ticks=in.nextInt();
				lock1.turnLeft(ticks);
			}
			else if(choice==4)
			{
				lock1.open();
			}
			else
			{
				System.out.println("Please make a valid choice");
			}
			
		}while(choice!=4);

    }
}