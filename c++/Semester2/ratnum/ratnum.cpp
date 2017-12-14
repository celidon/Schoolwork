//This is the file: ratnum.cpp.
//This is the implementation for the class RatNum.
//The interface for the class RatNum is in the header file ratnum.h.

#include <iostream>
#include "ratnum.h"

using namespace std;

void RatNum::normalize()
{
    if(dem%2==0 && num%2==0)
    {
        dem=dem/2;
        num=num/2;
    }
    if(dem%3==0 && num%3==0)
    {
        dem=dem/3;
        num=num/3;
    }
    if(dem%5==0 && num%5==0)
    {
        dem=dem/5;
        num=num/5;
    }
    if(dem%7==0 && num%7==0)
    {
        dem=dem/7;
        num=num/7;
    }
    if(dem%num==0)
    {
        dem=dem/num;
        num=num/num;
    }
    if(dem<0)
    {
        num=num*-1;
        dem=dem*-1;
    }
}

bool operator==(const RatNum& left, const RatNum& right)
{
    return(left.num*right.dem==right.num*left.dem);
}

bool operator<(const RatNum& left, const RatNum& right)
{
    return(left.num*right.dem<right.num*left.dem);
}

bool operator>(const RatNum& left, const RatNum& right)
{
    return(left.num*right.dem>right.num*left.dem);
}

bool operator<=(const RatNum& left, const RatNum& right)
{
    return(left.num*right.dem<=right.num*left.dem);
}

bool operator>=(const RatNum& left, const RatNum& right)
{
    return(left.num*right.dem>=right.num*left.dem);
}

RatNum operator+(const RatNum& a, const RatNum& b)
{
	RatNum temp;
	temp.num = a.num * b.dem + b.num * a.dem;
	temp.dem = a.dem * b.dem;

	temp.normalize();

	return temp;
}

RatNum operator-(const RatNum& a, const RatNum& b)
{
	RatNum temp;
	temp.num = a.num * b.dem - b.num * a.dem;
	temp.dem = a.dem * b.dem;

	temp.normalize();

	return temp;
}

RatNum operator/(const RatNum& a, const RatNum& b)
{
	RatNum temp;
	temp.num = a.num * b.dem;
	temp.dem = a.dem * b.num;

	temp.normalize();

	return temp;
}

RatNum operator*(const RatNum& a, const RatNum& b)
{
	RatNum temp;
	temp.num = a.num * b.num;
	temp.dem = a.dem * b.dem;

	temp.normalize();

	return temp;
}

ostream& operator<<(ostream& out, const RatNum& r)
{
	if (r.dem == 0)
		out << "undefined" ;
	else
		out << r.num << "/" << r.dem;
	return out;

}

istream& operator>>(istream& in, RatNum& r)
{
    char slash='/';

    in >> r.num>>slash>> r.dem;
	return in;
}

RatNum::RatNum()
{
	num = 0;
	dem = 1;
}

RatNum::RatNum(int _num, int _dem)
{
	num = _num;
	dem = _dem;
}

RatNum::RatNum(int whole)
{
	num = whole;
	dem = 1;
}