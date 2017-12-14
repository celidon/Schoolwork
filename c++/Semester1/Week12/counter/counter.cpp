/*
File Name: counter.cpp
Developer: Anthony Hansen
Date Last Modified: 03.12.2013
Description: The assignment was to write a class CounterType containing the
             following: a default constructor setting the count to 0, a second
             constructor setting the count to whatever number the user wants,
             two member functions that allow the count to go up or down, a
             member function that outputs the count using 'ostream', and a
             member function that returns the count. This class and member
             functions are to be placed in a test program.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class CounterType
{
public:
    CounterType(int number);
    CounterType();
    int up();
    int down();
    int getcount();
    void output(ostream& outs);

private:
    int counter;
};

int main()
{
    int j;
    char ans;
    CounterType counts(199), i;

    cout<<"We are now going to print 'Hello, World' 200 times and count along\n";
    cout<<"Ready? y/n\n";
    cin>>ans;

    if(ans=='y'||ans=='y')
        do{
            i.up();
            j=i.getcount();
            cout<<"Hello, World\n";
            counts.output(cout);
            counts.down();
        }while(j<200);
    else
    {
        cout<<"Goodbye";
    }

    return 0;
}


CounterType::CounterType()
{
    counter = 0;
}

CounterType::CounterType(int number)
{
    if(number<0)
    {
        cout << "Illegal value for counter.\n";
        exit(0);
    }
    counter = number;
}

int CounterType::up()
{
    if(counter<0)
    {
        cout << "Illegal value for counter.\n";
        exit(0);
    }
    counter++;
}

int CounterType::down()
{
    if(counter<0)
    {
        cout << "Illegal value for counter.";
        exit(0);
    }
    counter--;
}

int CounterType::getcount()
{
    return counter;
}

void CounterType::output(ostream& out)
{
    out << "Count: " << counter << endl;
}
