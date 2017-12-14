/*
File Name: Homework14.cpp
Developer: Anthony Hansen
Date Last Modified: 17.09.2013
Description: The assignment was to write a program that uses multiple custom
             functions in order to tell the user if they're consuming enough
             calories to make up for their exercise and natural body processes.
             The program needs the user's weight, intensity of work out, length
             of work out and how many calories they intake.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cmath>

using namespace std;

double weight;

double metabolic_rate();
double physical_activity();
double caloric_intake();

int main()
{
    char answer;

    answer == 'y';

    do{
        cout<<"How much do you weigh in pounds?\n";
        cin>>weight;

        double serving_size = (metabolic_rate() + physical_activity()) /  caloric_intake();

        cout<<"In order to balance your diet,\n"<<"you need to eat "<<serving_size<<" servings.\n";

        cout<<"Do you wish to repeat the calculations? y/n \n";
        cin>>answer;

    }while (answer == 'y' || answer == 'Y');

    while (answer == 'n' || answer == 'N')
    {
        cout<<"Happy exercising!\n";
        break;
    }

    return 0;
}
//Calories burned by the metabolism during normal daily processes
double metabolic_rate()
{
    double metabolism;

    metabolism = 70 * (pow((weight / 2.2 ), 0.756));

    return metabolism;
}
//Calories burned during exercise routines
double physical_activity()
{
    double intensity;
    double time;
    double calories_burned;

    cout<<"How long do you work out in minutes?\n";
    cin>>time;

    cout<<"What is the intensity of your work out?\n";
    cin>>intensity;

    calories_burned = 0.0385 * intensity * weight * time;

    return calories_burned;
}
//Amountof calories we retain after digesting our food
double caloric_intake()
{
    double calories;
    double calories_required;

    cout<<"Please input the number of calories you recieve\n"<<"from one serving of your favourite food.\n";
    cin>>calories;

    calories_required = (calories - (calories * 0.1));

    return calories_required;
}
