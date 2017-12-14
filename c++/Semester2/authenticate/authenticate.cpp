/*
   File Name: authenticate.cpp
   Developer: Anthony Hansen
   Date Last Modified: 21.03.2014
   Description: The assignment was to take a set of predefined functions and
				finish declaring and defining necessary functions in an unnamed
				namespace in order for the following predefined test program to
				run properly.
Email Address: hansen.tony92@gmail.com
*/


#include <iostream>
#include "password.h"
#include "username.h"

using namespace Authenticate;

int main()
{
	inputUserName();
	inputPassword();
	cout<<"Username: "<<getUserName()<<endl;
	cout<<"Password: "<<getPassword()<<endl;
	
	return 0;
}