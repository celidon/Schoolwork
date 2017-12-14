/*
File Name: Homework10.cpp
Developer: Anthony Hansen
Date Last Modified: 8.09.2013
Description: The assignment was to write a program that outputs the amount
             of green crud that has grown after a certain number of days.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

int main()
{
    double amount_final;
    double amount_initial;
    double amount_second;
    int count;
    int days;
    char answer;

    do
    {
        cout<<"How many days has the green crud been growing?\n";
        cin>> days;

        int time = ((days - 5) / 5);

        amount_initial = 10;
        amount_second = 0;
        count = 0;

        while (count <= time)
        {
            amount_final = amount_second + amount_initial;

            amount_second = amount_initial;
            amount_initial = amount_final;
            count ++;
        }

        cout<<"After "<< days <<" days, there will be\n";
        cout<<amount_final <<" pounds of green crud.\n";

        cout<<"Would you like to recalculate? y / n \n";
        cin>> answer;
    }
    while ((answer == 'y') ||(answer == 'Y'));

    cout<<"Good-bye";

    return 0;
}
