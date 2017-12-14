/*
   File Name: rationalnumbers.cpp
   Developer: Anthony Hansen
   Date Last Modified: 25.02.2014
   Description: The assignment was to write a program that uses a class and
				operator assignments in order to edit, add, subtract, divide,
				multiply, and compare rational numbers(specifically fractions)
Email Address: hansen.tony92@gmail.com
*/


#include<iostream>

using namespace std;

class Rational
{
	private:
		int num,dem;
		void normalize();
	public:
		Rational();
		Rational(int,int);
		Rational(int);
		friend ostream& operator<<(ostream& , const Rational&);
		friend istream& operator>>(istream& , Rational&);
		friend Rational operator+(const Rational& , const Rational&);
		friend Rational operator-(const Rational& , const Rational&);
		friend Rational operator/(const Rational& , const Rational&);
		friend Rational operator*(const Rational& , const Rational&);
		friend bool operator==(const Rational&, const Rational&);
		friend bool operator>(const Rational&, const Rational&);
		friend bool operator<(const Rational&, const Rational&);
		friend bool operator>=(const Rational&, const Rational&);
		friend bool operator<=(const Rational&, const Rational&);

};


void Rational::normalize()
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

bool operator==(const Rational& left, const Rational& right)
{
    return(left.num*right.dem==right.num*left.dem);
}

bool operator<(const Rational& left, const Rational& right)
{
    return(left.num*right.dem<right.num*left.dem);
}

bool operator>(const Rational& left, const Rational& right)
{
    return(left.num*right.dem>right.num*left.dem);
}

bool operator<=(const Rational& left, const Rational& right)
{
    return(left.num*right.dem<=right.num*left.dem);
}

bool operator>=(const Rational& left, const Rational& right)
{
    return(left.num*right.dem>=right.num*left.dem);
}

Rational operator+(const Rational& a, const Rational& b)
{
	Rational temp;
	temp.num = a.num * b.dem + b.num * a.dem;
	temp.dem = a.dem * b.dem;

	temp.normalize();

	return temp;
}

Rational operator-(const Rational& a, const Rational& b)
{
	Rational temp;
	temp.num = a.num * b.dem - b.num * a.dem;
	temp.dem = a.dem * b.dem;

	temp.normalize();

	return temp;
}

Rational operator/(const Rational& a, const Rational& b)
{
	Rational temp;
	temp.num = a.num * b.dem;
	temp.dem = a.dem * b.num;

	temp.normalize();

	return temp;
}

Rational operator*(const Rational& a, const Rational& b)
{
	Rational temp;
	temp.num = a.num * b.num;
	temp.dem = a.dem * b.dem;

	temp.normalize();

	return temp;
}

ostream& operator<<(ostream& out, const Rational& r)
{
	if (r.dem == 0)
		out << "undefined" ;
	else
		out << r.num << "/" << r.dem;
	return out;

}

istream& operator>>(istream& in, Rational& r)
{
    char slash='/';

    in >> r.num>>slash>> r.dem;
	return in;
}

Rational::Rational()
{
	num = 0;
	dem = 1;
}

Rational::Rational(int _num, int _dem)
{
	num = _num;
	dem = _dem;
}

Rational::Rational(int whole)
{
	num = whole;
	dem = 1;
}

int main()
{

	Rational a;
	Rational b(1,2);
	Rational c(10);


	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	cout << "Enter the rational number as num/dem:";
	cin >> a;
	cout << "a=" << a << endl;
	cout << "a+b= " << (a + b) << endl;
	cout << "a-b= " << (a - b) << endl;
	cout << "a/b= " << (a / b) << endl;
	cout << "a*b= " << (a * b) << endl;
	cout << "a<=c\n" << (a<=c ? "a is less than or equal to c":"a is not less than or equal to c") <<endl;
	cout << "a>b\n" << (a>b ? "a is greater than b":"a is not greater than b") <<endl;


	return 0;
}
