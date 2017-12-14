//This is the file: triangle.cpp.
//This is the implementation for the class Triangle.
//The interface for the class Triangle is in the header file triangle.h.

#include <iostream>
#include "triangle.h"
using namespace std;

namespace shapes
{
	Triangle::Triangle()
	{
		cout<<"Triangle constructor\n";
	}
	void Triangle::draw()
	{
		cout<<"Triangle draw method\n";
	}
	void Triangle::erase()
	{
		cout<<"Triangle erase method\n";
	}
	void Triangle::center()
	{
		cout<<"Triangle center method\n";
		cout<<"Calling erase\n";
		erase();
		cout<<"Calling draw\n";
		draw();
	}
}