/*
File Name: rockpaperscissorslizardspock.cpp
Developer: Anthony Hansen
Date Last Modified: 10.09.2013
Description: The assignment was to write a program that will play Rock,
             Paper, Scissors with the user. I got bored and editted it
             to play Rock, Paper, Scissors, Lizard, Spock, a better
             verison with a higher probabilty of winning/losing.
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

    cout<<"Rock, Paper, Scissors, Lizard, Spock is a\n" ;
    cout<<"game similar to Rock, Paper, Scissors\n";
    cout<<"but with more options.\n";
    cout<<"Here's the rules:\n";
    cout<<"Scissors cut Paper, Paper covers Rock, Rock crushes Lizard,\n";
    cout<<"Lizard poisons Spock, Spock smashes Scissors, Scissors decapitate Lizard,\n";
    cout<<"Lizard eats Paper, Paper disproves Spock, Spock vaporizes Rock,\n";
    cout<<"and, as it always has, Rock breaks Scissors.\n";
    cout<<"Are you ready to play Rock, Paper, Scissors, Lizard, Spock? y / n \n";
    cin>>answer;

    while (answer == 'y')
    {
        cout<< "Please choose your weapon.\n";
        cout<< "1 for rock\n"<<"2 for paper\n"<<"3 for scissors\n"<<"4 for lizard\n"<<"5 for Spock\n";
        cin>> choice;

        int enemy = (rand() % 5) + 1;

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
                else if (enemy == 5)
                {
                    cout<< "Foolish human, Spock vaporizes Rock. You lose.\n";
                }
                else if (enemy == 4)
                {
                    cout<<"You won! Rock crushes Lizard.\n";
                }
                else
                {
                    cout<<"You won! Rock breaks Scissors\n";
                }
            }
            else if (choice == 2)
            {
                if (enemy == 3)
                {
                    cout<< "Foolish human, Scissors cut Paper. You lose.\n";
                }
                else if (enemy == 4)
                {
                    cout<< "Foolish human, Lizard eats Paper. You lose.\n";
                }
                else if (enemy == 5)
                {
                    cout<<"You won! Paper disproves Spock.\n";
                }
                else
                {
                    cout<<"You won! Paper covers Rock.\n";
                }
            }
            else if (choice == 3)
            {
                if (enemy == 1)
                {
                    cout<< "Foolish human, Rock breaks Scissors. You lose.\n";
                }
                else if (enemy == 5)
                {
                    cout<< "Foolish human, Spock smashes Scissors. You lose.\n";
                }
                else if (enemy == 4)
                {
                    cout<<"You won! Scissors decapitate Lizard.\n";
                }
                else
                {
                    cout<<"You won! Scissors cut Paper.\n";
                }
            }
            else if (choice == 4)
            {
                if (enemy == 1)
                {
                    cout<< "Foolish human, Rock crushes Lizard. You lose.\n";
                }
                else if (enemy == 3)
                {
                    cout<< "Foolish human, Scissors decapitate Lizard. You lose.\n";
                }
                else if (enemy == 2)
                {
                    cout<<"You won! Lizard eats Paper.\n";
                }
                else
                {
                    cout<<"You won! Lizard poisons Spock.\n";
                }
            }
            else if (choice == 5)
            {
                if (enemy == 2)
                {
                    cout<< "Foolish human, Paper disproves Spock. You lose.\n";
                }
                else if (enemy == 4)
                {
                    cout<< "Foolish human, Lizard poisons Spock. You lose.\n";
                }
                else if (enemy == 1)
                {
                    cout<<"You won! Spock vaporizes Rock.\n";
                }
                else
                {
                    cout<<"You won! Spock smashes Scissors.\n";
                }
            }
            else
            {
                cout<< "You didn't choose 1, 2, 3, 4, 5.\n";
            }
        }
    cout<<"Play again? y/n \n";
    cin>> answer;
    }

    while (answer == 'n')
    {
        cout<<"Okay. Good bye then.\n";

    break;
    }

    return 0;
}
