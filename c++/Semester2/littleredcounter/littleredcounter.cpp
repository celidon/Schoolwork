/*
   File Name: littleredcounter.cpp
   Developer: Anthony Hansen
   Date Last Modified: 20.02.2014
   Description: The assignment was to write a program that simulated a little
                red counter. It allows the user to determine the size of the
                counter and to increment it by 1, 10, 100, or 1000 as well as
                having a reset and detection for overflow.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void setCounter();

class Counter
{
    int currentcount;

    public:
    int num;
    Counter();
    Counter(int);
    void reset();
    void incr1(int);
    void incr10(int);
    void incr100(int);
    void incr1000(int);
    bool overflow();
    void display();
};

int main()
{
    char choice;
    int innum, num;

    cout<<"A little red counter, just like mom's\n";

    cout<<"How high would you like the counter to go?\n";
    cin>>num;

    Counter littlered(num);

    littlered.num=num;

    cout<<"Please make a selection:\n a-cents\n s-tens of cents\n d-dollars\n";
    cout<<" f-tens of dollars\n o-Check for overflow\n r-Reset the counter\n e-Exit\n";

    do
    {
        cout<<"What would you like to do?\n";
        cin>>choice;

        if(choice=='a')
        {
            cout<<"By how many cents would you like to increase the counter?\n";
            cin>>innum;

            littlered.incr1(innum);
        }
        else if(choice=='s')
        {
            cout<<"By how many tens of cents would you like to increase the counter?\n";
            cin>>innum;

            littlered.incr10(innum);
        }
        else if(choice=='d')
        {
            cout<<"By how many dollars would you like to increase the counter?\n";
            cin>>innum;

            littlered.incr100(innum);
        }
        else if(choice=='f')
        {
            cout<<"By how many tens of dollars would you like to increase the counter?\n";
            cin>>innum;

            littlered.incr1000(innum);
        }
        else if(choice=='o')
        {
            littlered.overflow();
        }
        else if(choice=='e')
        {
            break;
        }
        else if(choice=='r')
        {
            littlered.reset();
        }
        else
        {
            cout<<"Please make a choice:\n";
        }

        littlered.display();

    }
    while(choice!='e');

    cout<<"Goodbye!";


    return 0;
}
//Constructor for a blank counter
Counter::Counter()
{
    num=9999;
    currentcount=0;
}
//Constructor for filling the counter
Counter::Counter(int num)
{
    if(num<0)
    {
        cout << "Illegal value for counter.\n";
        exit(0);
    }
    currentcount = 0;
}
//Display counter
void Counter::display()
{
    if(currentcount>=num)
    {
        overflow();
    }
    else
    {
        cout<<endl<<"Currently: "<<currentcount<<endl<<endl;
    }
}
//Resetting counter
void Counter::reset()
{
    currentcount=0;
}
//Increment by 1
void Counter::incr1(int innum)
{
    currentcount+=1*innum;
}
//Increment by 10
void Counter::incr10(int innum)
{
    currentcount+=10*innum;
}
//Increment by 100
void Counter::incr100(int innum)
{
    currentcount+=100*innum;
}
//Increment by 1000
void Counter::incr1000(int innum)
{
    currentcount+=1000*innum;
}
//Overflow check
bool Counter::overflow()
{
    if(currentcount<=num)
    {
        cout<<endl<<"Under the limit\n";
    }
    else
    {
        cout<<endl<<"Overflow\n Counter will be reset to zero\n";
        reset();
    }
}

