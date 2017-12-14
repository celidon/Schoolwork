/*
File Name: timer.cpp
Developer: Anthony Hansen
Date Last Modified: 03.10.2013
Description: The assignment was to write a program that allows the user to
             enter the current time in AM/PM format and then enter an amount
             of time that they wich to wait. The program will output the time
             the user will be done waiting in AM/PM format.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

void time();

using namespace std;

int main()
{
    char answer;

    do{
        cout<<"Would you like to set up a timer? y/n\n";
        cin>>answer;

        if(answer == 'y' || answer == 'Y')
        {
            time();
        }
        else if(answer == 'n' || answer == 'N')
        {
            break;
        }
        else
        {
            cout<<"Please make a choice.\n";
        }
    }while(answer != 0);

    cout<<"Goodbye\n";
    return 0;
}

void time()
{
    char colon, day1, day2;
    int current_hour, current_minute, wait_hour, wait_minute, final_hour, final_minute;

    cout<<"What time is it now?\n";
    cin>>current_hour>>colon>>current_minute>>day1>>day2;

    //Converting the time to 24 hour style in order to make calculations easier.
    if (day1 == 'p' || day1 == 'P')
    {
        current_hour = current_hour + 12;
    }
    else if (current_hour == 12 && (day1 == 'a' || day1 == 'A'))
    {
        current_hour = current_hour - 12;
    }

    cout<<"How many hours do you want to wait?\n";
    cin>>wait_hour;

    cout<<"How many minutes do you want to wait?\n";
    cin>>wait_minute;

    //Determining the new minute part of the time and removing any additional hours.
    final_minute = ((current_minute + wait_minute) % 60);

    //Determining the new hour of the time and putting it into AM/PM format.
    final_hour = ((current_hour + wait_hour)+((current_minute + wait_minute) / 60));

    //If no further calculation is needed, the first character in the AM/PM part will be 'A'
    day1 = 'A';
    //The second charcter in the AM/PM part of the time will always be 'M'
    day2 = 'M';

    //Further calculations to determine the AM/PM portion of the output and to properly convert back into AM/PM format
    //Because anything after noon is PM
    if (final_hour == 12)
    {
        day1 = 'P';
    }

    //In case the wait time causes a crossing of a time meridian(midnight or noon)
    if (final_hour >= 24)
    {
        final_hour = final_hour - 24;

        day1 = 'A';
        //So in case it is in the minutes after midnight
        if (final_hour == 0)
        {
            final_hour = 12;
        }
    }
    else if (final_hour > 12)
    {
        final_hour = final_hour - 12;

        day1 = 'P';
    }

    if (final_minute == 0 || final_minute < 10)
    {
        cout<<"It will be "<<final_hour<<":0"<<final_minute<<day1<<day2<<endl;
    }
    else
    {
        cout<<"It will be "<<final_hour<<":"<<final_minute<<day1<<day2<<endl;
    }

    return;
}
