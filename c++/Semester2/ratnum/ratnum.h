//This is the header file ratnum.h.
//This is the interface for the class RatNum.

#ifndef RATNUM_H
#define RATNUM_H

#include <iostream>

using namespace std;

class RatNum
{
	private:
		int num,dem;
		void normalize();
	public:
		RatNum();
		RatNum(int,int);
		RatNum(int);
		friend ostream& operator<<(ostream& , const RatNum&);
		friend istream& operator>>(istream& , RatNum&);
		friend RatNum operator+(const RatNum& , const RatNum&);
		friend RatNum operator-(const RatNum& , const RatNum&);
		friend RatNum operator/(const RatNum& , const RatNum&);
		friend RatNum operator*(const RatNum& , const RatNum&);
		friend bool operator==(const RatNum&, const RatNum&);
		friend bool operator>(const RatNum&, const RatNum&);
		friend bool operator<(const RatNum&, const RatNum&);
		friend bool operator>=(const RatNum&, const RatNum&);
		friend bool operator<=(const RatNum&, const RatNum&);

};

#endif