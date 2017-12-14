/*
File Name: lgnumadd.cpp
Developer: Anthony Hansen
Date Last Modified: 06.11.2013
Description: The assignment was to write a program that prompts for two numbers
             and adds them together, storing the data in dynamically allocated
             arrays. The input will be taken as a string and then converted to
             an array of type int.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void program();
char checkNum(string, int);
void fillArray(int [], string, int);
void addArray(int [], int [], int [], int, int);
void printArray(int [], int);

int main()
{
    char ans;

    do{
        cout<<"Would you like to add two large numbers? y/n\n";
        cin>>ans;
        if(ans=='y' || ans=='Y')
        {
            program();
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
        }

    }while(ans!='n');

    cout<<"Goodbye";

    return 0;
}

//All the math and function calls necessary to add the two arrays
//It is all here to keep main cleaner
void program()
{
    string num;
    char ans;
    int len_num1, len_num2;

    do{
        cout<<"Please enter the first number:\n";
        cin>>num;
        len_num1=num.size();
        ans = checkNum(num, len_num1);
    }while(ans != 'y');

    int *num1 = new int[len_num1];
    fillArray(num1, num, len_num1);

    do{
        cout<<"Please enter the second number:\n";
        cin>>num;
        len_num2=num.size();
        ans = checkNum(num, len_num2);
    }while(ans != 'y');

    int *num2 = new int[len_num2];
    fillArray(num2, num, len_num2);

    cout<<endl;

    if(len_num1>len_num2)
    {
        int *sum = new int[len_num1];
        addArray(num1, num2, sum, len_num1, len_num2);
        printArray(sum, len_num1);
    }
    else
    {
        int *sum = new int[len_num2];
        addArray(num2, num1, sum, len_num2, len_num1);
        printArray(sum, len_num2);
    }
    cout<<endl;
}

//Checking that all the characters that were input are integers
char checkNum(string num, int length)
{
    char ans;

    for(int i=0; i<length; i++)
    {
        int current=static_cast<int>(num[i]);

        if(current>=48 && current<=57)
        {
            ans='y';
        }
        else
        {
            ans='n';
            cout<<num[i]<<" is not a number.\n";
            break;
        }
    }

    return ans;
}

//Filling an integer array with the input from a string
void fillArray(int arr[], string num, int length)
{
    for(int i=0; i<length; i++)
    {
        arr[i]=static_cast<int>(num[i])-48;
    }
}

//The actual addition of the two arrays
void addArray(int arrBig[], int arrSmall[], int arr3[], int sizeBig, int sizeSmall)
{
    int change = sizeBig-sizeSmall;

    //Filling the sum array with the values of the longer array
    for(int k=0; k<change; k++)
    {
        arr3[k]=arrBig[k];
    }
    //Adding the ends of the arrays together
    for(int i=0; i<sizeSmall; i++)
    {
        arr3[i+change]=arrBig[i+change]+arrSmall[i];
    }
    //Taking the sum array and finishing the addition by making certian each part
    //of the array is less than 9
    for(int j=sizeBig-1; j>0; j--)
    {
        if(arr3[j]>9)
        {
            arr3[j]=arr3[j]%10;
            arr3[j-1]=arr3[j-1]+1;
        }
    }
}

//Printing out an array
void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i];
    }
}
