#include<iostream>
#include "username.h" 


using namespace std;
/*
	This is the file username.cpp
	It is the implementation of the file username.h
*/
namespace Authenticate
{
	// stuff for the implementation
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}

namespace
{
	
	
	// private implementation to the compilation unit
	bool isValid()
	{
		bool letter=false;
		//Verify that only letters are being used
		for(int i=0;i<username.length();i++)
		{
			if(username[i]<=122&&username[i]>=97||username[i]>=65&&username[i]<=90)
			{
				letter=true;
			}
		}
		
		return (username.length() == 8 && letter==true);
	}
}