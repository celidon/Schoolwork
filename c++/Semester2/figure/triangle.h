//This is the header file triangle.h.
//This is the interface for the class Triangle.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of triangles.
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

using namespace std;

namespace shapes
{

    class Triangle:public Figure
    {
    public:
        Triangle();
		void draw();
		void erase();
		void center();

    };

}//shapes

#endif //TRIANGLE_H