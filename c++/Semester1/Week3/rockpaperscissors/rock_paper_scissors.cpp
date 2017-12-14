/*
File Name: rock_paper_scissors.cpp
Developer: Anthony Hansen
Date Last Modified: 12.09.2013
Description: The assignment was to write a program that will play Rock,
             Paper, Scissors with the user.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    char answer;
    int choice;

    cout<<"Are you ready to play Rock, Paper, Scissors? y / n \n";
    cin>>answer;

    while ((answer == 'y') || (answer == 'Y'))
    {
        int enemy = (rand() % 3) + 1;

        cout<< "Please choose your weapon.\n";
        cout<< "1 for rock\n"<<"2 for paper\n"<<"3 for scissors\n";
        cin>> choice;

        if (choice == enemy)
        {
            cout<< "It's a tie!\n";
        }
        else
        {
            if (choice == 1)
            {
                if (enemy == 2)
                {
                    cout<< "Foolish human, Paper covers Rock. You lose.\n";
                }

                else
                {
                    cout<< "You won! Rock smashes Scissors.\n";
                }
            }
            else if (choice == 2)
            {
                if (enemy == 3)
                {
                    cout<< "Foolish human, Scissors cut Paper. You lose.\n";
                }
                else
                {
                    cout<< "You won! Paper covers Rock\n";
                }
            }
            else if (choice == 3)
            {
                if (enemy == 1)
                {
                    cout<< "Foolish human, Rock smashes Scissors. You lose.\n";
                }
                else
                {
                    cout<< "You won! Scissors cut Paper.\n";
                }
            }
            else
            {
                cout<< "You didn't choose 1, 2, or 3.\n";
            }
        }
    cout<<"Play again? y / n \n";
    cin>> answer;
    }

    while ((answer == 'n') || (answer == 'N'))
    {
        cout<<"Okay. Goodbye then.\n";

    break;
    }

    return 0;
}
