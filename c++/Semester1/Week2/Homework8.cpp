/*
File Name: Homework8.cpp
Developer: Anthony Hansen
Date Last Modified: 8.09.2013
Description: The assignment was to write a program that prompts for an inflation
             rate to predict how much pencils will cost after a certian period of
             time
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

int main()
{
    double inflation_rate;
    double time;
    double cost_pencils;
    double amount_pencils;
    double total;
    double start = 0;

    cout<< "How many pencils do you want to buy?";
    cin>> amount_pencils;

    cout<< "How much does one pencil cost in dollars?";
    cin>> cost_pencils;

    cout<< "What is the percent rate of inflation?";
    cin>> inflation_rate;

    inflation_rate = inflation_rate * .01;

    cout<< "In how many years do you want to buy these pencils?";
    cin>> time;

    while (start < time)
    {
        cost_pencils = cost_pencils + inflation_rate * cost_pencils;
        start++;
    }

    total = cost_pencils * amount_pencils;

    cout<< "After " << time << " years, ";
    cout<< amount_pencils << " pencils will cost $";
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<< total << endl;
    cout<< "at $" << cost_pencils << " a pencil.\n";

    return 0;
}
