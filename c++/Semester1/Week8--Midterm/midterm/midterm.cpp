/*
File Name: midterm.cpp
Developer: Anthony Hansen
Date Last Modified: 15.10.2013
Description: The assignment was to write a program that has a fibonacci number calculating function.
             The function will take an integer as a parameter which is the fibonacci number to calculate,
             and return the fibonacci number. Then use this function to calculate the sum of every
             fibonacci number that is divisible by 3 or 5. Do this for all fibonacci numbers less than
             4,000,000.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

void fib_num(int);

int main()
{
    int number;

    cout<<"To which of the first 47 Fibonacci numbers do you want to calculate?\n";

    cin>>number;

    if(number <= 47)
    {
        fib_num(number);
    }
    else
    {
        cout<<"Invalid option. Program ceases to run properly after the 47th Fibonacci number.\n";
    }

    return 0;
}

void fib_num(int number)
{
    unsigned int amount_final, amount_initial, amount_second, sum;
    int count;

    sum = 0;
    amount_initial = 1;
    amount_second = 0;
    amount_final = 0;
    count = 1;

    //The Fibonacci number calculator
    while(count <= number)
        {
            amount_final = amount_second + amount_initial;

            amount_initial = amount_second;
            amount_second = amount_final;

            count ++;

            //The sum equation to find the sum of all Fibonacci numbers less than 4000000 and divisible by 3 or 5
            if((amount_final % 3 == 0 || amount_final % 5 == 0) && amount_final < 4000000)
            {
                sum = amount_final + sum;
            }
        }

    cout<<"The "<<number<<" Fibonacci number is "<<amount_final<<endl;

    if(amount_final < 4000000)
    {
        cout<<"The sum of all Fibonacci numbers less than "<<amount_final<<endl;
        cout<<"and divisible by 3 or 5 is "<<sum<<endl;
    }
    else
    {
        cout<<"The sum of all Fibonacci numbers less than 4000000\n";
        cout<<"and divisible by 3 or 5 is "<<sum<<endl;
    }

    return;
}
