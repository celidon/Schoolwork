//This is the header file polynomial.h.
//This is the interface for the class Polynomial.

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

using namespace std;

class Polynomial
{
	public:
		Polynomial();
		Polynomial(Polynomial& other);
		Polynomial(int);
		Polynomial(int, int);
		~Polynomial();
		void input();
		void output();
		void addPoly(Polynomial&, Polynomial&);
		void subPoly(Polynomial&, Polynomial&);
		void multPoly(Polynomial&, Polynomial&);
		void evalPoly();
		friend Polynomial operator+(Polynomial& , Polynomial&);
		friend Polynomial operator-(Polynomial& ,Polynomial&);
		friend Polynomial operator*(Polynomial& ,Polynomial&);
		
	private:
		int coef, exp;
		Polynomial *link;
};

#endif