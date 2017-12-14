//This is the header file rectangle.h.
//This is the interface for the class Rectangle.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of rectangles.
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

using namespace std;

namespace shapes
{

    class Rectangle:public Figure
    {
    public:
        Rectangle();
		void draw();
		void erase();
		void center();

    };

}//shapes

#endif //RECTANGLE_H
