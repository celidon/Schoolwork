/*
File Name: Exercise5.cpp
Developer: Anthony Hansen
Date Last Modified: 5.09.2013
Description: The assignment was to write a program that prompts for two numbers
             and then adds and multiplies them
Email Address: hansen.tony92@gmail.com
*/
#include <iostream>

using namespace std;

int main()
{
    int integer1, integer2, sum, product;

    cout<<"Press return after giving your response.\n";
    cout<<"Please enter a number.\n";

    cin>>integer1;

    cout<<"Please enter another number.\n";

    cin>>integer2;

    sum = integer1 + integer2;
    product = integer1 * integer2;

    cout<<"The sum of ";
    cout<<integer1;
    cout<<" and ";
    cout<<integer2;
    cout<<" is: ";
    cout<<sum;
    cout<<".\n";

    cout<<"The product of ";
    cout<<integer1;
    cout<<" and ";
    cout<<integer2;
    cout<<" is: ";
    cout<<product;
    cout<<".\n";

    return 0;
}
