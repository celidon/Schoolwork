/*
	This is the file password.cpp
	It is the implementation of the file password.h
*/

#include<iostream>
#include "password.h"

namespace Authenticate
{
	// stuff for the implementation
	void inputPassword()
	{
		do{
			cout<<"Enter your password (at least 8 characters and at least one nonletter)\n";
			cin>>password;
		}while(!isValid());
	}

	string getPassword()
	{
		return password;
	}
}

namespace
{
	// private implementation to the compilation unit
   bool isValid()
	{
		bool nonChar=false;
		
		for(int i=0;i<password.length();i++)
		{
			if((password[i]>122||password[i]<97)&&(password[i]<65||password[i]>90))
			{
				nonChar=true;
			}
		}
		
		return (password.length() >=  8 && nonChar==true);
	}
}