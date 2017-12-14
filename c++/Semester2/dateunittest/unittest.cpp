/*
	File Name: unittest.cpp
	Developer: Anthony Hansen
	Date Last Modified: 29.04.2014
	Description: The assignment was to download the code from boss and edit it
				 so that the unit tests used templates and another unit test for
				 != was written.
	Email Address: hansen.tony92@gmail.com
*/

//This is the file unittest.cpp
//It is the test program for date.h. please find declarations and implementations
//of the Date class in the appropriate files.

#include <iostream>
#include <cassert>

#include "Date.h"

using namespace std;

template<class T>
void assertIf_GT(T a,T b)
{
	assert(a > b);
}

template<class T>
void assertIf_LT(T a,T b)
{
	assert(a < b);
}

template<class T>
void assertIf_NE(T a,T b)
{
	assert(a!=b);
}
int main(){
	Date d;

	d.setYear(-1);
	assertIf_GT(d.getYear(),0);
	assertIf_LT(0,d.getYear());
	assertIf_NE(d.getYear(),-1);
	
	return 0;
}