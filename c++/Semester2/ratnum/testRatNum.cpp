/*
   File Name: testRatNum.cpp
   Developer: Anthony Hansen
   Date Last Modified: 20.03.2014
   Description: The assignment was to rewrite the program that uses a class and
				operator assignments in order to edit, add, subtract, divide,
				multiply, and compare rational numbers(specifically fractions)
				and place the ADT into separate files in order to demonstrate
				separate compilation.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include "ratnum.h"

using namespace std;

int main()
{

	RatNum a;
	RatNum b(1,2);
	RatNum c(10);


	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	cout << "Enter the rational number as num/dem:";
	cin >> a;
	cout << "a=" << a << endl;
	cout << "a+b= " << (a + b) << endl;
	cout << "a-b= " << (a - b) << endl;
	cout << "a/b= " << (a / b) << endl;
	cout << "a*b= " << (a * b) << endl;
	cout << "a<=c\n" << (a<=c ? "a is less than or equal to c":"a is not less than or equal to c") <<endl;
	cout << "a>b\n" << (a>b ? "a is greater than b":"a is not greater than b") <<endl;


	return 0;
}