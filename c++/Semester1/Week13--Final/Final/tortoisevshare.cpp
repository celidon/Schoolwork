/*
File Name: tortoisevshare.cpp
Developer: Anthony Hansen
Date Last Modified: 05.12.2013
Description: The assignment was to write a program that races the tortoise
             against the hare. The race is over 70 spaces. The hare moves
             forward, slips backward, and sleeps. The tortoise moves forward
             or slips backward. The winner is whoever crosses the finish line
             first.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

void zeroArray(char [], int);
void printArray(char [], int);
int hare(int);
int tortoise(int);

using namespace std;

int main()
{
    srand(time(0));
    char race[72];
    int t=0, h=0;

    cout<<"\nBANG!!!\nAND THEY'RE OFF!\n";

    do{
        zeroArray(race,72);

        int tick=rand()%100+1;
        h=h+hare(tick);
        t=t+tortoise(tick);

        if(t<0)
        {
            t=0;
        }
        else if(h<0)
        {
            h=0;
        }

        if(t==h || h==t)
        {
            race[t]='O';
            race[t+1]='U';
            race[t+2]='C';
            race[t+3]='H';
            race[t+4]='!';
        }
        else
        {
            race[t]='T';
            race[h]='H';
        }

        printArray(race,72);
        cout<<endl;

    }while(t<=70 && h<=70);

    if(t>=70)
    {
        cout<<"Tortoise wins! Yay!\n";
    }
    else if(h>=70)
    {
        cout<<"Hare wins... Yawn...\n";
    }
    else if(t>=70 && h>=70)
    {
        cout<<"The tortoise and the hare tie!\n THE PLATYPUS WINS!!!!\n";
    }

    return 0;
}

//Printing out an array
void printArray(char arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
}
//Filling the array with NULL and drawing the finish line
void zeroArray(char arr[], int size)
{
    for(int i=0; i<size; i++)
        {
            arr[i]='\0';
        }

    arr[size-1]='|';
}

//The movement rules of the hare
int hare(int num)
{
    int pos;

    if(num<=20)
    {
       pos=0;
    }
    else if(num>20 && num<=40)
    {
        pos=9;
    }
    else if(num>40 && num<=50)
    {
        pos=-12;
    }
    else if(num>50 && num<=80)
    {
        pos=1;
    }
    else if(num>80 && num<=100)
    {
        pos=-2;
    }

    return pos;
}

//The movement rules of the tortoise
int tortoise(int num)
{
    int pos;

    if(num<=50)
    {
       pos=3;
    }
    else if(num>50 && num<=70)
    {
        pos=-6;
    }
    else if(num>70 && num<=100)
    {
        pos=1;
    }

    return  pos;
}
