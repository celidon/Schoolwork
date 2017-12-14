//This is the header file suitor.h.
//This is the interface for the class Suitor.

#ifndef SUITOR_H
#define SUITOR_H

#include <iostream>

using namespace std;

class Suitor
{
	public:
		Suitor();
		Suitor(int);
		void deleteSuitor();
		void input(int);
		void suitorPicker(int);

	private:
		int number;
		Suitor *link, *head;
};

#endif