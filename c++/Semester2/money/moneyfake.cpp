#include <iostream>

using namespace std;

class Money
{
    public:
        Money();
	    Money(long);
	    Money(long,int);

        Money percent(int);

        int getAllCents();
		int getCents();
		int getDollars();

    private:
        long all_cents;

};

Money::Money()
{
   all_cents = 0;
}

Money::Money(long _all_cents)
{
	all_cents = _all_cents;
}

int Money::getAllCents()
{
	return all_cents;
}

int Money::getCents()
{
	return all_cents % 100;
}

int Money::getDollars()
{
	return all_cents/100;
}

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
	Money temp(percent_of_money_object);

	return temp;
}

int main()
{

    Money purse(10010);
    Money purse2(1010);
    Money purse3(40010);
    Money purse4(80010);
    Money purse5(5010/ 10 + 5 -100);

    Money new_purse = purse.percent(10);

	if(new_purse.getCents()<10)
	{
	    cout<<"$"<<new_purse.getDollars()<<".0"<<new_purse.getCents()<<endl;
	}
	else
    {
        cout<<"$"<<new_purse.getDollars()<<"."<<new_purse.getCents()<<endl;
    }
	// The output should be $10.01

	return 0;
}
