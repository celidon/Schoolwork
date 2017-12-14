/*
	File Name: date.cpp
	Developer: Anthony Hansen
	Date Last Modified: 29.04.2014
	Description: The assignment was to download the code from boss and edit it
				 so that the unit tests used templates and another unit test for
				 != was written.
	Email Address: hansen.tony92@gmail.com
*/

//This is the implementation of the Date class.

#include "Date.h"
Date::Date()
{
}

Date::Date(int m,int d)
{ 
}

Date::Date(std::string d)
{
}
	
void Date::setYear(int y)
{
	year = y;
}

int Date::getYear()
{
	return year;
}

std::string Date::format(std::string s)
{
	std::string str("m/d/y");
	return str;
}