/*
File Name: average.cpp
Developer: Anthony Hansen
Date Last Modified: 10.10.2013
Description: The assignment was to write a program that opens a data file
             containing only numbers of type double and then takes the
             average of all these numbers and outputs it on the screen.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    double next, sum, average;
    int count;
    ifstream in_stream;

    sum = 0;
    count = 0;

    in_stream.open("input1.dat");
    if (in_stream.fail())
    {
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    while (in_stream >> next)
    {
        sum = sum + next;
        count ++;
    }

    average = sum / count;

    cout<<"The average is "<<average<<".\n";

    in_stream.close();

    return 0;
}
