/*
	File Name: date.h
	Developer: Anthony Hansen
	Date Last Modified: 29.04.2014
	Description: The assignment was to download the code from boss and edit it
				 so that the unit tests used templates and another unit test for
				 != was written.
	Email Address: hansen.tony92@gmail.com
*/

//This is the declaration of the Date class

#ifndef DATE_H
#define DATE_H
#include<string>

class Date
{
	int day,month,year,hour,minute;

	public:
		Date();
		Date(int,int);
		Date(std::string);
	
		void setYear(int);
		int getYear();
		std::string format(std::string);
};
#endif