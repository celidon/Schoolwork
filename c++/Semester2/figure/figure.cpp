//This is the file: figure.cpp.
//This is the implementation for the class Figure.
//The interface for the class Figure is in the header file figure.h.

#include <iostream>
#include "figure.h"
using namespace std;

namespace shapes
{
	Figure::Figure()
	{
		cout<<"Figure constructor\n";
	}
	void Figure::draw()
	{
		cout<<"Figure draw method\n";
	}
	void Figure::erase()
	{
		cout<<"Figure erase method\n";
	}
	void Figure::center()
	{
		cout<<"Figure center method\n";
		cout<<"Calling erase\n";
		erase();
		cout<<"Calling draw\n";
		draw();
	}
}
