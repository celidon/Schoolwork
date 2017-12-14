/*
   File Name: Tickets.java
   Developer: Anthony Hansen
   Date Last Modified: 18.03.2014
   Description: The assignment was to write a program that allows tickets to be
				purchased from a theatre. The program first creates the theatre
				using a two dimensional array. It then allows ticket purchases
				by either price or seat until all the seats are full. If a seat
				is taken, the price is changed to 0.
Email Address: hansen.tony92@gmail.com
*/

import java.util.Scanner;

public class Tickets
{	
	public static Scanner in = new Scanner(System.in);

	public static void emptyTheatre(int theatre[][], int size)
	{
		int i, j;
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<size;j++)
			{
				theatre[i][j]=10;
			}
		}
		for(i=3;i<6;i++)
		{
			for(j=0;j<2;j++)
			{
				theatre[i][j]=10;
			}
			for(j=2;j<size-2;j++)
			{
				theatre[i][j]=20;
			}
			for(j=size-2;j<size;j++)
			{
				theatre[i][j]=10;
			}
		}
		for(i=6;i<7;i++)
		{
			for(j=0;j<2;j++)
			{
				theatre[i][j]=20;
			}
			for(j=2;j<4;j++)
			{
				theatre[i][j]=30;
			}
			for(j=4;j<6;j++)
			{
				theatre[i][j]=40;
			}
			for(j=6;j<8;j++)
			{
				theatre[i][j]=30;
			}
			for(j=8;j<size;j++)
			{
				theatre[i][j]=20;
			}
			
		}
		for(i=7;i<9;i++)
		{
			for(j=0;j<1;j++)
			{
				theatre[i][j]=20;
			}
			for(j=1;j<3;j++)
			{
				theatre[i][j]=30;
			}
			for(j=3;j<4;j++)
			{
				theatre[i][j]=40;
			}
			for(j=4;j<6;j++)
			{
				theatre[i][j]=50;
			}
			for(j=6;j<7;j++)
			{
				theatre[i][j]=40;
			}
			for(j=7;j<9;j++)
			{
				theatre[i][j]=30;
			}
			for(j=9;j<size;j++)
			{
				theatre[i][j]=20;
			}
		}
		for(i=9;i<10;i++)
		{
			for(j=0;j<1;j++)
			{
				theatre[i][j]=30;
			}
			for(j=1;j<2;j++)
			{
				theatre[i][j]=40;
			}
			for(j=2;j<8;j++)
			{
				theatre[i][j]=50;
			}
			for(j=8;j<9;j++)
			{
				theatre[i][j]=40;
			}
			for(j=9;j<size;j++)
			{
				theatre[i][j]=30;
			}
		}
	}
	
	public static void printTheatre(int theatre[][], int size)
	{
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				System.out.print(theatre[i][j]+" ");
			}
			System.out.print("\n");
		}
	}
	
	public static void seatTheatre(int theatre[][],int size,int tickets)
	{
		int t=0;
		int price=0;
		
		while(t<tickets)
		{
			System.out.println("Which row would you like to sit in?");
			int row=in.nextInt();
			if(row-1<size&&row!=0)
			{
				System.out.println("Which column would you like to sit in?");
				int column=in.nextInt();
				if(column-1<size&&column!=0)
				{
					if(theatre[row-1][column-1]!=0)
					{
						price=price+theatre[row-1][column-1];
						theatre[row-1][column-1]=0;
						t++;
					}
					else
					{
						System.out.println("Seat already taken. Try again");
					}
				}
				else
				{
					System.out.println("No column "+column);
				}
			}
			else
			{
				System.out.println("No row "+row);
			}
		}
		System.out.println("Your tickets will cost: $"+price);
	}
	
	public static void priceTheatre(int theatre[][],int size,int tickets)
	{
		int price=0;
		int t=0;
		boolean seat;
		int row, col, i, j;
		
		System.out.println("What price tickets do you want?");
		int tprice=in.nextInt();
		
		System.out.println("Your seats are: ");
		
		while(t<tickets&&tprice!=0)
		{
			seat=checkSeats(theatre,size,tprice);
			if(seat==true)
			{
				for(i=size-1; i>=0; i--)
				{
					for(j=0; j<size;j++)
					{
						if(theatre[i][j]==tprice&&t<tickets)
						{
							theatre[i][j]=0;
							row=i+1;
							col=j+1;
							System.out.println("Row: "+row+" Col: "+col);
							t++;
							price=price+tprice;
							break;
						}	
					}			
				}
			}
			else
			{
				System.out.println("No more seats are available for that price.");
				System.out.println("Would you like to go down one price level? y/n");
				char choice=in.next().charAt(0);
				if(choice=='y')
				{
					tprice=tprice-10;
				}
				else
				{
					break;
				}
			}
		}
		System.out.println("Your tickets will cost: $"+price);		
	}
	
	public static boolean checkSeats(int theatre[][],int size,int tprice)
	{		
		boolean availseat=false;
		
		for(int i=size-1; i>=0; i--)
		{
			for(int j=0; j<size;j++)
			{
				if(theatre[i][j]==tprice)
				{
					availseat=true;
				}
			}
		}
		
		return availseat;
	}

	public static void main(String[] args)
	{		
		int size=10;
		int [][] theatre=new int[size][size];
		int i=0;
		int total=0;
		
		emptyTheatre(theatre,size);
		
		do{
			printTheatre(theatre,size);
	
			System.out.println("How many tickets do you want?");
			int tickets=in.nextInt();
		
			System.out.println("Would you like to buy tickets by price or by seat?\n1:Price\n2:Seat");
			int choice=in.nextInt();
		
			do{
				if(choice==1)
				{
					priceTheatre(theatre,size,tickets);
					break;
				}
				else if(choice==2)
				{
					seatTheatre(theatre,size,tickets);
					break;
				}
				else
				{
					System.out.println("Please make a choice");
					choice=in.nextInt();
				}
			}while(choice!=1||choice!=2);
		
			System.out.println("Thank you and enjoy the show\n\n");
			total=total+tickets;
			
		}while(total<100);
		
		System.out.println("SOLD OUT!");
	}
}