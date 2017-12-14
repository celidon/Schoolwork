//This is the file: rectangle.cpp.
//This is the implementation for the class Rectangle.
//The interface for the class Rectangle is in the header file rectangle.h.

#include <iostream>
#include "rectangle.h"
using namespace std;

namespace shapes
{
	Rectangle::Rectangle()
	{
		cout<<"Rectangle constructor\n";
	}
	void Rectangle::draw()
	{
		cout<<"Rectangle draw method\n";
	}
	void Rectangle::erase()
	{
		cout<<"Rectangle erase method\n";
	}
	void Rectangle::center()
	{
		cout<<"Rectangle center method\n";
		cout<<"Calling erase\n";
		erase();
		cout<<"Calling draw\n";
		draw();
	}
}