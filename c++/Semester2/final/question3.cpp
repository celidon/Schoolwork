/*
 File Name: question3.cpp
 Description: Assume proper includes have been executed, but not using directive
			  or declaration. Write a definition of an iterator for a vector
			  named vec of int values. Write a for loop that will display the 
			  contents vec on the screen, separated by spaces. Use iterators for
		 	  the loop control.
 Author: Anthony Hansen
 Email Address: hansen.tony92@gmail.com
 Date Created:  Thu May 29 15:25:07 PDT 2014
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vec;
    for(int i=0;i<100;i++)
    {
        vec.push_back(i);
    }
    for (vector<int>::iterator it = vec.begin(); it!=vec.end(); it++)
    {
        cout <<*it<<" ";
    }

    return 0;
}

