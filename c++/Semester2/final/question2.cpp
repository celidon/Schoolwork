/*
 File Name: question2.cpp
 Description: Assume proper includes have been executed, but no using directive
 			  or declaration. Write a definition of an iterator for a vector of
			  ints that is initialized to point to the first member of the
			  vector vec.
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
	vector<int>::iterator it = vec.begin();
    for (it;it!=vec.end(); it++)
    {
        cout <<*it<<" ";
    }

    return 0;
}

