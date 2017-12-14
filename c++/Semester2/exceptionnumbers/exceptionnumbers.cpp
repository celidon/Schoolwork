/*
   File Name: exceptionnumbers.cpp
   Developer: Anthony Hansen
   Date Last Modified: 06.05.2014
   Description: The assignment was to write a program that prompted for a number
				It then checked to see that the number was actually a number and
				not a list of characters. It also tested to see if the number was
				between 1 and 10. If the number failed either test, the program
				was thrown an exception. After successfully passing both tests,
				the program gave a histograph of the number of times each number
				was entered.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void printData(int a)
{
	for(int i=0; i<a;i++)
	{
		cout<<'*';
	}
	cout<<endl;
}

int main()
{
	int n1=0;
	int n2=0;
	int n3=0;
	int n4=0;
	int n5=0;
	int n6=0;
	int n7=0;
	int n8=0;
	int n9=0;
	int n10=0;
	string in;
	int nums;
	int input;
	
	cout<<"How many numbers to enter?\n";
	cin>>nums;
	
	cout<<"Please enter "<<nums<<"numbers between 1 and 10\n";
	
	for(int i=0; i<nums; i++)
	{
		int p=i;
		try{
			cout<<"Enter "<<i+1<<" number:\n";
			cin>>in;
		
			for(int j=0;j<in.length();j++)
			{
				if(!isdigit(in[j]))
				{
					throw in;
				}
			}
		
			input=atoi(in.c_str());
			
			if(input<=0||input>10)
			{
				throw in;
			}
		}
		catch(string in)
		{
			cout<<in<<" is not a number or is not in the proper range.\n"		cout<<"Input must be a number inclusively between 1 and 10. Please try again.\n";
			p--;
		}
		
		if(p==i)
		{
			if(input==1)
			{
				n1++;
			}
			else if(input==2)
			{
				n2++;
			}
			else if(input==3)
			{
				n3++;
			}
			else if(input==4)
			{
				n4++;
			}
			else if(input==5)
			{
				n5++;
			}
			else if(input==6)
			{
				n6++;
			}
			else if(input==7)
			{
				n7++;
			}
			else if(input==8)
			{
				n8++;
			}
			else if(input==9)
			{
				n9++;
			}
			else if(input==10)
			{
				n10++;
			}
		}
		else
		{
			i=p;
		}
	}
	cout<<"Here is a histogram of values:\n";
	cout<<"1:";
	printData(n1);
	cout<<"2:";
	printData(n2);
	cout<<"3:";
	printData(n3);
	cout<<"4:";
	printData(n4);
	cout<<"5:";
	printData(n5);
	cout<<"6:";
	printData(n6);
	cout<<"7:";
	printData(n7);
	cout<<"8:";
	printData(n8);
	cout<<"9:";
	printData(n9);
	cout<<"10:";
	printData(n10);
	
	return 0;
}