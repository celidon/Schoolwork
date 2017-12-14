/*
File Name: Homework2.cpp
Developer: Anthony Hansen
Date Last Modified: 8.09.2013
Description: The assignment was to write a program that prompts for two weights
             and a volume to predict how much diet soda a dieter can drink without
             dying.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

int main()
{
    const double soda_sweetner = .001;
    double weight_mouse;
    double weight_dieter;
    double sweetner;
    double soda;
    double death;

    cout<<"How much artificial sweetner in liters is needed to kill a mouse?";
    cin>> sweetner;

    cout<<"How much does a mouse weigh in grams?";
    cin>> weight_mouse;

    death = (weight_mouse / 1000)/ sweetner; //Turning the weight of the mouse into kilograms and finding the lethal ratio

    cout<<"At what weight in pounds do you want to stop dieting?";
    cin>> weight_dieter;

    weight_dieter = weight_dieter / 2.205; //Converting the dieter's weight into kilograms

    soda = (weight_dieter / death) / soda_sweetner; //Finding where the dieter hits said lethal ratio

    cout<<"You can drink up to ";
    cout<<soda;
    cout<<" liters of soda.";

    return 0;
}
