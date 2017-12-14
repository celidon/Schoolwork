/*
   File Name: money.cpp
   Developer: Anthony Hansen
   Date Last Modified: 27.02.2014
   Description: The assignment was to edit a program that uses a class and
				operator assignments in order to edit, add, subtract, divide,
				multiply currency. The edits were to add functions that allow
				a percentage of the money to be output and overload the boolean
				comparison operators(<,>,<=,>=).
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

//Class for amounts of money in U.S. currency.
class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount);

    friend bool operator ==(const Money& amount1, const Money& amount2);

    friend bool operator <=(const Money& amount1, const Money& amount2);

    friend bool operator >=(const Money& amount1, const Money& amount2);

    friend bool operator >(const Money& amount1, const Money& amount2);

    friend bool operator <(const Money& amount1, const Money& amount2);

    Money percent(int);

    Money(long dollars, int cents);

    Money(long dollars);

    Money( );

    double get_value( ) const;

    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream,
    //then outs has already been connected to a file.

        void input(istream&);

        void output(ostream&);
    private:
        long all_cents;

};

int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.


//NEW--Declared by the student for the assignment
Money Money::percent(int percentage)
{
	/*
	When declaring a new object, use the existing cents value
	and get the percentage by multiplying the percentage value
	parameter by the existing cents value.  This will give you
	the percentage, use that as the value when constructing the
	temporary Money object, then return the new temporary Money object
	*/
	int percent_of_money_object = all_cents*percentage/100;
	Money temp(0, percent_of_money_object);

	return temp;
}

int main( )
{
    int interest;

    Money purse;

    cout<<"Please input the amount of original money in the form '$00.00':\n";

    purse.input(cin);

    cout<<"Please input the percentage to multiply by:\n";

    cin>>interest;

    Money newpurse=purse.percent(interest);

    Money compare=purse.percent(5);

    cout<<interest<<"% of ";

    purse.output(cout);

    cout<<" is ";

    newpurse.output(cout);

    cout<<endl;

    cout<<(compare<newpurse ? "5% of the original amount is less than ":"5% of the original amount isn't less than ");

    newpurse.output(cout);

    cout<<endl;

    return 0;
}
//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;


return ins;
}

int digit_to_int(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}
//NEW--Declared by the student for the assignment
bool operator <=(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents <= amount2.all_cents);
}
//NEW--Declared by the student for the assignment
bool operator >=(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents >= amount2.all_cents);
}
//NEW--Declared by the student for the assignment
bool operator <(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}
//NEW--Declared by the student for the assignment
bool operator >(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents > amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive


{
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}

double Money::get_value( ) const
{
    return (all_cents * 0.01);
}

//Uses iostream, cctype, cstdlib:
void Money::input(istream& ins)
{
    char one_char, decimal_point,
         digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )


    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    all_cents = dollars*100 + cents;
    if (negative)
        all_cents = -all_cents;
}

void Money::output(ostream& outs)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}
