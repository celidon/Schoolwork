/*
File Name: month.cpp
Developer: Anthony Hansen
Date Last Modified: 03.12.2013
Description: The assignment was to write a class that includes the following
             member functions: default constructor, constructor that accepts
             month names as characters, constructor that accepts intergers as
             months, an input function for intergers, an input function for
             characters, an output function that outputs intergers corresponding
             a month, an output function that outputs the names of the months,
             and a function that finds the next month. Then the class was to be
             put into a test program.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Month
{
public:
    Month(char, char, char);
    Month(int);
    Month();
    void charin(istream&);
    void intin(istream&);
    void charout(ostream&);
    void intout(ostream&);
    int next();

private:

    int month;

};

int main()
{
    Month now;

    cout<<"Enter the month:\n";
    now.charin(cin);
    now.charout(cout);
    cout<<" is the ";
    now.intout(cout);
    cout<<" month";
    now.next();
    cout<<endl<<"The next month is the ";
    now.intout(cout);
    cout<<" month or ";
    now.charout(cout);
    cout<<endl;

    cout<<"Enter the number of a month:\n";
    now.intin(cin);
    cout<<"The ";
    now.intout(cout);
    cout<<" month is ";
    now.charout(cout);
    now.next();
    cout<<endl<<"The next month is the ";
    now.intout(cout);
    cout<<" month or ";
    now.charout(cout);
    cout<<endl;
    return 0;
}

//Transforming month names into numbers
Month::Month(char first, char second, char third)
{
    if((first=='j'||first=='J')&&(second=='a'||second=='A')&&(third=='n'||third=='N'))
        month = 1;
    else if((first=='f'||first=='F')&&(second=='e'||second=='E')&&(third=='b'||third=='B'))
        month = 2;
    else if((first=='m'||first=='M')&&(second=='a'||second=='A')&&(third=='r'||third=='R'))
        month = 3;
    else if((first=='a'||first=='A')&&(second=='p'||second=='P')&&(third=='r'||third=='R'))
        month = 4;
    else if((first=='m'||first=='M')&&(second=='a'||second=='A')&&(third=='y'||third=='Y'))
        month = 5;
    else if((first=='j'||first=='J')&&(second=='u'||second=='U')&&(third=='n'||third=='N'))
        month = 6;
    else if((first=='j'||first=='J')&&(second=='u'||second=='U')&&(third=='l'||third=='L'))
        month = 7;
    else if((first=='a'||first=='A')&&(second=='u'||second=='U')&&(third=='g'||third=='G'))
        month = 8;
    else if((first=='s'||first=='S')&&(second=='e'||second=='E')&&(third=='p'||third=='P'))
        month = 9;
    else if((first=='o'||first=='O')&&(second=='c'||second=='C')&&(third=='t'||third=='T'))
        month = 10;
    else if((first=='n'||first=='N')&&(second=='o'||second=='O')&&(third=='v'||third=='V'))
        month = 11;
    else if((first=='d'||first=='D')&&(second=='e'||second=='E')&&(third=='c'||third=='C'))
        month = 12;
    else
    {
        cout << "Invalid Month\n";
        exit(0);
    }
}

//Checking that the month intergers are valid
Month::Month(int date)
{
    if(date>=1 || date<=12)
    {
        month=date;
    }
    else
    {
        cout<<"Invaild month\n";
    };
}

Month::Month()
{
    month=0;
}

//Input of month name and transform into number
void Month::charin(istream& ins)
{
    char first, second, third;
    ins>>first>>second>>third;

    if((first=='j'||first=='J')&&(second=='a'||second=='A')&&(third=='n'||third=='N'))
        month = 1;
    else if((first=='f'||first=='F')&&(second=='e'||second=='E')&&(third=='b'||third=='B'))
        month = 2;
    else if((first=='m'||first=='M')&&(second=='a'||second=='A')&&(third=='r'||third=='R'))
        month = 3;
    else if((first=='a'||first=='A')&&(second=='p'||second=='P')&&(third=='r'||third=='R'))
        month = 4;
    else if((first=='m'||first=='M')&&(second=='a'||second=='A')&&(third=='y'||third=='Y'))
        month = 5;
    else if((first=='j'||first=='J')&&(second=='u'||second=='U')&&(third=='n'||third=='N'))
        month = 6;
    else if((first=='j'||first=='J')&&(second=='u'||second=='U')&&(third=='l'||third=='L'))
        month = 7;
    else if((first=='a'||first=='A')&&(second=='u'||second=='U')&&(third=='g'||third=='G'))
        month = 8;
    else if((first=='s'||first=='S')&&(second=='e'||second=='E')&&(third=='p'||third=='P'))
        month = 9;
    else if((first=='o'||first=='O')&&(second=='c'||second=='C')&&(third=='t'||third=='T'))
        month = 10;
    else if((first=='n'||first=='N')&&(second=='o'||second=='O')&&(third=='v'||third=='V'))
        month = 11;
    else if((first=='d'||first=='D')&&(second=='e'||second=='E')&&(third=='c'||third=='C'))
        month = 12;
    else
    {
        cout << "Invalid Month\n";
        exit(0);
    }
}

//Input of month number and validity check
void Month::intin(istream& ins)
{
    int date;

    ins>>date;

    if(date>=1 || date<=12)
    {
        month=date;
    }
    else
    {
        cout<<"Invaild month\n";
    };

}

//Printing month names
void Month::charout(ostream& out)
{
    if(month==1)
    {
        out<<"Jan";
    }
    else if(month==2)
    {
        out<<"Feb";
    }
    else if(month==3)
    {
        out<<"Mar";
    }
    else if(month==4)
    {
        out<<"Apr";
    }
    else if(month==5)
    {
        out<<"May";
    }
    else if(month==6)
    {
        out<<"Jun";
    }
    else if(month==7)
    {
        out<<"Jul";
    }
    else if(month==8)
    {
        out<<"Aug";
    }
    else if(month==9)
    {
        out<<"Sep";
    }
    else if(month==10)
    {
        out<<"Oct";
    }
    else if(month==11)
    {
        out<<"Nov";
    }
    else if(month==12)
    {
        out<<"Dec";
    }
}

//Printing month number
void Month::intout(ostream& out)
{
    out<<month;
}

//Finding the next month
int Month::next()
{
    month++;
    if(month>12)
    {
        month=month-12;
    }
    return month;
}

