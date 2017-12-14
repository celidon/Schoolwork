/*
File Name: leapyear.cpp
Developer: Anthony Hansen
Date Last Modified: 15.09.2013
Description: The assignment was to write a program that prompts for a year and then tells the
             user if it is a leap year.
Email Address: hansen.tony92@gmail.com
*/
#include <iostream>

using namespace std;

int main()
{
    int year;

    do
    {
    cout<<"Enter '0' to end.\n";
    cout<<"Please insert the year you want to know about:\n";
    cin>> year;

    if((year % 4 == 0) &&  (year % 100 != 0) || (year % 400 == 0))
		{
			cout << year <<" is a leap year.\n";
		}
    else
		{
			cout << year <<" is not a leap year.\n";
		}
	} while(year != 0);

	return 0;
}
