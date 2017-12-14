/*
File Name: feet_meter_converter.cpp
Developer: Anthony Hansen
Date Last Modified: 26.09.2013
Description: The assignment was to write a program allows the user to choose what they want to convert
             and allows the user to convert a measurement from feet and inches into meters and centimeters
             or from meters and centimeters to feet.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

void feet_meters();
void meters_feet();

int main()
{
    int choice;

    cout<<"This is a converter between feet and meters.\n";

    do{
        cout<<"Please choose what you'd like to convert:\n";
        cout<<"1 Feet to Meters\n"<<"2 Meters to Feet\n"<<"0 End Program\n";
        cin>> choice;

        if (choice == 1)
        {
            feet_meters();
        }
        else if(choice == 2)
        {
            meters_feet();
        }
    }while(choice != 0);

    cout<<"Goodbye!";

    return 0;
}

//Converts feet to meters
void feet_meters()
{
    char var, var1, var2, var3;
    int feet, meters;
    double distance, metric, centimeters, inches;

    cout<<"Please input the length in feet and inches.\n";
    cout<<"Please use the format:00ft00.00in\n";
    cin>>feet>>var>>var1>>inches>>var2>>var3;

    distance = feet*12 + inches;

    metric = distance*2.54;

    meters = metric/100;

    centimeters = (metric - meters*100);

    cout<<feet<<"ft "<<inches<<"in is "<<meters<<"m "<<centimeters<<"cm.\n";

    return;
}

//Converts meters to feet
void meters_feet()
{
    char var1, var2, var3;
    int meters, feet;
    double distance, metric, inches, centimeters;

    cout<<"Please input the length in meters and centimeters.\n";
    cout<<"Please use the format:00m00.00cm\n";
    cin>>meters>>var1>>centimeters>>var2>>var3;

    metric = meters*100 + centimeters;

    distance = metric/2.54;

    feet = distance/12;

    inches = distance - feet*12;

    cout<<meters<<"m "<<centimeters<<"cm is "<<feet<<"ft "<<inches<<"in.\n";

    return;
}
