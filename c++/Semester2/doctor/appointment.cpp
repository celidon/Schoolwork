/*
   File Name: appointment.cpp
   Developer: Anthony Hansen
   Date Last Modified: 11.03.2014
   Description: The assignment was to create a base class Figure and two
				derived classes(Triangle and Rectangle). The member functions
				were only supposed to be stubs declaring what function was
				being used. Once it was compiled and ran without virtual
				functions and once with. Differences were recorded below.
Email Address: hansen.tony92@gmail.com
*/

/*
	The program seemed to run the same both with virtual functions and without.
	I did not notice a difference in either speed of compiling nor runtime.
*/

//This is the short test program written for the Doctor class.
//Please find all classes and function definitions in their appropriate files.

#include "doctor.h"
#include <iostream>

using namespace employeessavitch;

int main()
{
	Doctor newguy;
	Doctor diffdoc(newguy);
	char ans;
	
	newguy.set_doctor();
	
	cout<<"Here is your doctor's information so that you can set an appointment:\n";
	
	newguy.print_doctor();
	
	cout<<"Set an appointment with this doctor?(y/n): ";
	cin>>ans;
	
	if(ans=='y'||ans=='Y')
	{
		newguy.set_date();
	
		cout<<"Here is your appointment information:\n";
		
		newguy.print_appointment();
	}
	else
	{
		cout<<"Set an appointment with another doctor?(y/n): ";
		cin>>ans;
		
		if(ans=='y'||ans=='Y')
		{			
			cin.ignore();
			diffdoc.set_appointment();
	
			cout<<"Here is your appointment information:\n";
		
			diffdoc.print_appointment();
		}
	}
	
	cout<<"Goodbye\n";
	
	return 0;
}