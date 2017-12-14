/*
   File Name: deque.cpp
   Developer: Anthony Hansen
   Date Last Modified: 29.04.2014
   Description: The assignment was to use the STl in order to write a program
				that implemented a deque and used an iterator to cycle through
				and print it out.
	Email Address: hansen.tony92@gmail.com
*/

#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	deque<double> doubles;
	double x;
	
	cout<<"Please insert ten doubles: ";
	
	for(int i=0; i<10; i++)
	{
		cin>>x;
		doubles.push_back(x);
	}
	
	std::sort(doubles.begin(),doubles.end());
	
	cout << "The contents of the deque are:";
	for (deque<double>::iterator it = doubles.begin(); it!=doubles.end(); it++)
	{
		cout << ' ' << *it;
	}
	
	cout<<endl;
	
	return 0;
}