/*
File Name: computerlab.cpp
Developer: Anthony Hansen
Date Last Modified: 14.11.2013
Description: The assignment was to write a program that uses dynamically filled
             arrays to simulate a computer lab set up. The program needs to include
             a way to log users on and off and to search to see which users are
             logged on or off. It also should include a menu to organize the available
             options.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

typedef int* IntArrayPtr;

void zeroArray(IntArrayPtr []);
void printArray(IntArrayPtr []);
void login(IntArrayPtr []);
void logoff(IntArrayPtr []);
void searchNum(IntArrayPtr []);
void menu(IntArrayPtr []);

const int LABSIZE=4;
const int STATION[LABSIZE]={5, 6, 4, 3};

using namespace std;

int main()
{
    IntArrayPtr *labs;

    labs=new IntArrayPtr[LABSIZE];

    for(int i=0; i<LABSIZE; i++)
    {
        labs[i]=new int [STATION[i]];
    }

    zeroArray(labs);
    printArray(labs);
    menu(labs);

    return 0;
}
//The menu
void menu(IntArrayPtr labs[])
{
    int choice;

    do{
        cout<<"1) Login\n2) Logout\n3) Search\n4) Display\n5) Quit\n"<<endl;
        cout<<"What would you like to do?\n";
        cin>> choice;

        if(choice==1)
        {
            login(labs);
        }
        else if(choice==2)
        {
            logoff(labs);
        }
        else if(choice==3)
        {
            searchNum(labs);
        }
        else if(choice==4)
        {
            printArray(labs);
        }
        else if(choice==5)
        {
            break;
        }
        else
        {
            cout<<choice<<" is not an option.\n";
        }
    }while(choice!=5);

    cout<<"Goodbye\n";
}
//Filling the array with zeros so that there is something to display
void zeroArray(IntArrayPtr arr[])
{
    for(int i = 0; i < LABSIZE; i++)
    {
        int j=STATION[i];
        for(int k=0; k<j; k++)
        {
            arr[i][k] = 0;
        }

    }
}
//Printing out the matrix
void printArray(IntArrayPtr arr[])
{
    cout<<"LAB"<<setw(25)<<"STATION"<<endl;

    for(int i = 0; i < LABSIZE; i++)
    {
        int j=STATION[i];

        for(int k=0; k<j; k++)
        {
            cout<<setw(7)<<k+1;
        }

        cout<<endl<<i+1;

        for(int k=0; k<j; k++)
        {
            cout<<setw(7)<<arr[i][k];
        }

        cout<<endl<<endl;

    }
}
//Logging in users
void login(IntArrayPtr arr[])
{
    int idnum, lab, station;

    cout<<"Please input your ID number:\n";
    cin>>idnum;

    cout<<"Please enter the lab number:\n";
    cin>>lab;

    cout<<"Please enter the station number:\n";
    cin>>station;

    if(arr[lab-1][station-1]==0)
    {
        arr[lab-1][station-1]=idnum;
    }
    else
    {
        cout<<"There is already a user at Lab "<<lab<<" Station "<<station<<endl;
    }
}
//Logging out users
void logoff(IntArrayPtr arr[])
{
    int idnum;

    cout<<"Please enter the ID number you want to logoff:\n";
    cin>>idnum;

    for(int i=0; i<LABSIZE; i++)
    {
        int j=STATION[i];

        for(int k=0; k<j; k++)
        {
            if(arr[i][k]==idnum)
            {
                arr[i][k]=0;
            }
        }
    }
}
//Search function
void searchNum(IntArrayPtr arr[])
{
    int idnum;
    bool user=false;

    cout<<"Please enter the ID number you want to search for:\n";
    cin>>idnum;

    for(int i=0; i<LABSIZE; i++)
    {
        int j=STATION[i];

        for(int k=0; k<j; k++)
        {
            if(arr[i][k]==idnum)
            {
                cout<<"Lab "<<i+1<<" Station "<<k+1<<endl;
                user=true;
                break;
            }
        }
    }
    if(!user)
    {
        cout<<idnum<<" is not logged in currently\n";
    }
    cout<<endl;
}
