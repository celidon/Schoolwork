/*
   File Name: admin.cpp
   Developer: Anthony Hansen
   Date Last Modified: 11.03.2014
   Description: The assignment was to use predefined header and implementation
				files in order to create a derived class named "Administrator".
				This class needed to include an overloading of the print_check()
				function as well as proper getters and setters necessary for an
				administrator, beyond that needed for a standard employee.
Email Address: hansen.tony92@gmail.com
*/

//This is the short test program written for the Administrator class.
//Please find all classes and function definitions in their appropriate files.

#include "administrator.h"
#include <iostream>

using namespace employeessavitch;

int main()
{
	Administrator mrbigshot;
	
	mrbigshot.set_admin();
	
	mrbigshot.print();
	
	cout<<"\nMr Bigshot wants his money!\n";
	
	mrbigshot.print_check();
	
	return 0;
}