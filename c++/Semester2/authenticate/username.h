/*
	This is the file username.h
	It is the declaration of the functions found in username.cpp
*/

#include<string>

using namespace std;

namespace
{
	// private stuff to the compilation unit
	string username;
	bool isValid();
}

namespace Authenticate
{
	void inputUserName();
	string getUserName();
}