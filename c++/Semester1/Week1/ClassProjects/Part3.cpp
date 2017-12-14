/*
File Name: Part1.cpp
Developer: Anthony Hansen
Date Last Modified: 8.09.2013
Description: The assignment was to copy a program out of the book
            then modify it to say 'Hello' at the beginning and
            'Good-bye' at the end. Then modify it to divide and
            note the runtime error when dividing by 0
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

int main()
{
    int number_of_pods, peas_per_pod, total_peas;

    cout<< "Hello\n";
    cout<< "Press return after entering a number.\n";

    cout<< "Enter the number of pods:\n";
    cin>> number_of_pods;

    cout<< "Enter the number of peas in a pod:\n";
    cin>> peas_per_pod;

    total_peas = number_of_pods * peas_per_pod;

    cout<< "If you have ";
    cout<< number_of_pods;
    cout<< " pea pods\n";

    cout<< "and ";
    cout<< peas_per_pod;
    cout<< " peas in each pod, then\n";

    cout<< "you have ";
    cout<< total_peas;
    cout<< " peas in all the pods.\n";

    cout<< "Goodbye\n";

    return 0;
}

/*
The runtime error is as follows:

*/
