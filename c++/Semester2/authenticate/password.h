/*
	This is the file password.h
	It is the declaration of the functions found in password.cpp
*/

#include<string>

using namespace std;


namespace Authenticate
{
	 void inputPassword();
	 string getPassword();
}

namespace
{
	string password;
	bool isValid();
}