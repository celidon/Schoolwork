/*
   File Name: princess.cpp
   Developer: Anthony Hansen
   Date Last Modified: 22.03.2014
   Description: The assignment was to write a program using a circular linked
				list to simulate a princess choosing her suitor. The princess counts off the number of letters in her name and eliminates the suitor matching that spot in the list. She then continues with the next suitor in line. Upon reaching the end of the line, she continues counting where she left off at the front. This continues until only one suitor is left and that's the one she marries
   Email Address: hansen.tony92@gmail.com
*/

//This is only the test program. The Suitor class declarations and definitions
//are found in suitor.h and suitor.cpp respectively

#include <iostream>
#include "suitor.h"
#include<string>

using namespace std;

int main()
{	
	int s, namelen;
	string name;
	
	cout<<"What is the princess' first name?\n";//Book gives the name 'Eve'
	cin>>name;
	
	namelen=name.length();//Allowing for different name lengths other than 3
	
	cout<<"Many suitors are calling for the princess:\n";
	cin>>s;
	
	Suitor men(s);
	
	men.input(s);
	
	men.suitorPicker(namelen);
	
	//cout<<men.get_Suitor();
	
	return 0;
}