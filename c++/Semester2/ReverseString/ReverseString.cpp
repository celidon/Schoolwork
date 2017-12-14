/*
   File Name: ReverseString.cpp
   Developer: Anthony Hansen
   Date Last Modified: 04.02.2014
   Description: The assignment was to write a program that took a string in as
                input and then used pointers to reverse it by switching to where
                the front and rear pointers pointed.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

void stringreverse(istream&);

int main()
{
    char ans;

    do{
        cout<<"Would you like to reverse a string? y/n\n";
        cin>>ans;
        cin.ignore();
        if(ans=='y' || ans=='Y')
        {
            stringreverse(cin);
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
        }

    }while(ans!='n');

    cout<<"Good-bye!";

    return 0;
}

void stringreverse(istream& input)
{
    string cstr;
    int i=0;
    char *front, *rear;
    cout<<"Please enter the string you would like to reverse: \n";

    getline(input, cstr);
    int csize=cstr.size();

    front=new char;
    rear=new char;

    while(i<csize)
    {
        *front=cstr[i];
        *rear=cstr[csize-(i+1)];

        front=rear;

        cout<<*front;

        i++;
        front++;
        rear++;
    }
    cout<<endl;
}
