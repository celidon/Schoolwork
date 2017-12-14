/*
File Name: polyTest.cpp
Developer: Anthony Hansen
Date Last Modified: 27.03.2013
Description: The assignment was to write a program that uses linked lists
			 in order to simulate polynomials. An input, output, addition,
			 subtraction, multiplication, and evaluation functions were required.
			 As were a copy constructor, a destructor, and overloading the +, -,
			 and * operators.
Email Address: hansen.tony92@gmail.com
*/

//This is the test program for the Polynomial class.
//The class declaration and definitions can be found in
//"polynomial.h" and "polynomial.cpp" respectively.

#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
	Polynomial first, second, mod;
	
	first.input();
	second.input();
	
	cout<<"The third polynomial is a copy of the first.\n\n";
	
	Polynomial third(first);
	
	cout<<"First: ";
	first.output();
	
	cout<<"Second: ";
	second.output();
	
	cout<<"Third: ";
	third.output();
	cout<<endl;
	
	cout<<"First + Second: ";
	mod.addPoly(first, second);
	cout<<endl;
	
	cout<<"Third - Second: ";
	mod.subPoly(third, second);
	cout<<endl;
	
	cout<<"First * Second: ";
	mod.multPoly(first, second);
	cout<<endl;
	
	cout<<"Good-bye!\n";
	
	return 0;
}