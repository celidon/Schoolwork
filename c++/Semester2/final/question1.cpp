/*
 File Name: question1.cpp
 Description: Declare a stack template container to hold values of type double
 			  using the list container. Write the necessary include and using 
			  statements. Mention any appropriate cautions about syntax.  
 Author: Anthony Hansen
 Email Address: hansen.tony92@gmail.com
 Date Created: * Thu May 29 15:45:43 PDT 2014
*/
#include<iostream>
#include<list>
#include<stack>

using namespace std;

int main()
{
	//Make certian to have a space between angle brackets
	stack<int, list<int> > s;

	for(int i=0;i<100;i++)
	{
		s.push(i);
	}

	for(int i=0;i<100;i++)
	{
		s.pop();
	}

	return 0;
}
