//This is the header file figure.h.
//This is the interface for the class Figure.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of figures.
#ifndef FIGURE_H
#define FIGURE_H

using namespace std;

namespace shapes
{

    class Figure
    {
    public:
        Figure();
		virtual void draw();
		virtual void erase();
		virtual void center();

    };

}//shapes

#endif //FIGURE_H
