/*
File Name: Homework5.cpp
Developer: Anthony Hansen
Date Last Modified: 17.09.2013
Description: The assignment was to write a program that will calculate the
             cost of a long distance call when given the day of the week,
             the time at which the call occured, and the length of the call.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

int main()
{
    char day1, day2, answer;
    int time, length;
    double cost;

    cout<<"Would you like to calculate the cost of a long-distance call? y/n \n";
    cin>>answer;

    while (answer == 'y' || answer == 'Y')
    {
        cout<<"Please input the day of the week:\n";
        cin>> day1>> day2;

        cout<<"At what time did the call start?\n";
        cout<<"Please enter the time in 24 hour fashion without colons or spaces.\n";
        cin>> time;

        cout<<"How long was the call in minutes?\n";
        cin>> length;

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        if (((day1 == 'M') || (day1 == 'm') ||
            (day1 == 'T') || (day1 == 't') ||
            (day1 == 'W') || (day1 == 'w') ||
            (day1 == 'F') || (day1 == 'f')) &&
            ((day2 == 'O') || (day2 == 'o') ||
            (day2 == 'U') || (day2 == 'u') ||
            (day2 == 'E') || (day2 == 'e') ||
            (day2 == 'H') || (day2 == 'h') ||
            (day2 == 'R') || (day2 == 'r')))
        {
            // For business days between 8am and 6pm

            if ((time >= 800) || (time <= 1800))
            {
                cost = length * .40;
                cout<<"Your call costs $"<<cost<<".\n";
            }

            // For business days before 8am and after 6pm

            else
            {
                cost = length * .25;
                cout<<"Your call costs $"<<cost<<".\n";
            }
        }

        else
        {
            //For weekends

            cost = length * .15;
            cout<<"Your call costs $"<<cost<<".\n";
        }

        cout<<"Would you like to calculate the cost of another call? y/n \n";
        cin>>answer;
    }

    while (answer == 'n' || answer == 'N')
    {
        cout<< "Good-bye";
        break;
    }
    return 0;
}
