/*
File Name: Homework7.cpp
Developer: Anthony Hansen
Date Last Modified: 17.09.2013
Description: The assignment was to write a program that uses a custom function to
             calculate the force of gravity between two objects using the equation
             for universal gravitation. The inputs are to be the masses of the two
             objects and the distance between them.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

const double Gravity = 6.673e-8;

double gravity();

int main()
{
    char answer;

    answer = 'y';

    do{
    double force_gravity = gravity();
    cout<<"The force of gravity acting betweent the two objects is "<<force_gravity<<" dynes.\n";
    cout<<"Would you like to perform the calculation again? y/n\n";
    cin>>answer;
    }while (answer == 'y' || answer == 'Y');

    while (answer == 'n' || answer == 'N')
    {
        cout<<"Good-bye";
        break;
    }

    return 0;
}
//The function. It asks for everything it needs.
double gravity()
{
    double mass1, mass2, distance, Force;

    cout<<"What is the mass in grams of the first object?\n";
    cin>>mass1;

    cout<<"What is the mass in grams of the second object?\n";
    cin>>mass2;

    cout<<"What is the distance in centimeters between the two objects?\n";
    cin>>distance;

    Force = ((Gravity * mass1 * mass2)/(distance * distance));

    return Force;
}
