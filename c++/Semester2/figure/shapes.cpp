/*
   File Name: shapes.cpp
   Developer: Anthony Hansen
   Date Last Modified: 16.03.2014
   Description: The assignment was to use predefined header and implementation
				files in order to create a derived class named "Doctor".
				This class needed to include an overloading of the assignment
				operator as well as proper getters and setters necessary for the
				additional variables associated with a doctor.
Email Address: hansen.tony92@gmail.com
*/

//This is the short test program written for the Figures class.
//Please find all classes and function definitions in their appropriate files.

#include "figure.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>

using namespace shapes;

int main()
{
	Triangle tri;
	tri.draw();
	
	cout<<"\nDerived class Triangle object calling center().\n";
	
	tri.center();
	
	Rectangle rect;
	rect.draw();
	
	cout<<"\nDerived class Rectangle object calling center().\n";
	
	rect.center();
	
	return 0;
}