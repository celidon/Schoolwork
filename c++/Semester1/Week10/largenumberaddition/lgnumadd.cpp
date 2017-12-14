/*
File Name: lgnumadd.cpp
Developer: Anthony Hansen
Date Last Modified: 06.11.2013
Description: The assignment was to write a program that prompts for two numbers
             of twenty digits, put them into a character array, transfer them to
             an integer array and add them together one at a time.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

void program();
void printArray(int [], int);
void zeroArray(char [], int);
void zeroArray(int [], int);
void reverseArray(int [], char [], int);
int sizeArray(char arr[], int);
char checkNum(char [], int);
char checkSize(int);
void addArray(int [], int [], int[], int, int, int);
int arraySize(int[], int[], int, int);

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
    int numsize = 22, size1, size2, size3;

    char num1[numsize], num2[numsize], ans;

    cout<<"Numbers can only be 20 characters long.\n";

    do{
        cout<<"Please input the first number:\n";
        zeroArray(num1, numsize);
        cin>>num1;
        ans=checkNum(num1, numsize);
        if(ans=='y')
        {
            size1 = sizeArray(num1, numsize);
            ans=checkSize(size1);
        }
    }while(ans=='n');

    do{
        cout<<"Please input the second number:\n";
        zeroArray(num2, numsize);
        cin>>num2;
        ans=checkNum(num2, numsize);
        if(ans=='y')
        {
            size2 = sizeArray(num2, numsize);
            ans=checkSize(size2);
        }
    }while(ans=='n');

    int arr1[size1], arr2[size2];

    zeroArray(arr1, size1);
    zeroArray(arr2, size2);

    reverseArray(arr1, num1, size1);
    reverseArray(arr2, num2, size2);

    size3=arraySize(arr1, arr2, size1, size2);
    ans=arraySize(arr1, arr2, size1, size2);

    int arr3[size3];

    addArray(arr1, arr2, arr3, size1, size2, size3);

    if(ans!='n')
    {
        printArray(arr3, size3);
    }

    cout<<endl;

}

//Printing out an array
void printArray(int arr[], int size)
{
    int i;

    for(i = 1; i < size; i++)
    {
        cout<<arr[i];
    }
}

//Filling arrays with zeroes so that we don't random integers
void zeroArray(char arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}
void zeroArray(int arr[], int size)
{
    int i;

    for(i = 0; i < size+1; i++)
    {
        arr[i] = 0;
    }
}

//Filling an integer array with the input of a character array
void reverseArray(int arr[], char ary[], int size)
{

    int i, count = size;

    for(i = 0; i < size; i++)
    {
        count--;
        arr[count] = ary[i]-48;
    }
}

//Calculating the size of the character array so the integer array is the right size
int sizeArray(char arr[], int numsize)
{
    int size = 0;
    int i=0;

    while(i < numsize)
    {
        if(arr[i]!=0)
        {
            i++;
            size++;
        }
        else
            i++;
    }
    return size+1;
}

//Checking that the user input is actually a number and not a character
char checkNum(char arr[], int numsize)
{
    int i=0;
    char ans;

    while(i<numsize)
    {
        int current=static_cast<int>(arr[i]);

        if(current>=48 && current<=57 || current == 0)
        {
           ans = 'y';
           i++;
        }
        else
        {
            cout<<arr[i]<<" is not a number\n";
            ans = 'n';
            break;
        }
    }

    return ans;
}

//Determining the output array size
int arraySize(int arr1[], int arr2[], int size1, int size2)
{
    int size;
    char ans;

    if(size1<21 && size2<21)
    {
        if(size1>size2)
        {
            size=size1+1;
        }
        else
        {
            size=size2+1;
        }
    }
    else if(size1 == 21 || size2 == 21)
    {
        if(arr1[size1-1]+arr2[size2-1]<10)
        {
            size=21;
        }
        else
        {
            cout<<"Interger overflow\n";
            ans='n';
        }
    }

    return size;
    return ans;
}

//Checking that the user entered an array less than 20 characters
char checkSize(int size)
{
    char ans;

    if(size>21)
    {
        cout<<"Number too large.\n";
        ans='n';
    }
    else
    {
        ans='y';
    }
    return ans;
}

//Adding the arrays together
void addArray(int arr1[], int arr2[], int arr3[], int size1, int size2, int size)
{
    int i=0;

    if(size1>size2)
    {
        while(size>0)
        {
            while(i<size1)
            {
                while(i<size2)
                {
                    arr3[size]=arr1[i]+arr2[i];
                    if(arr3[size]> 9)
                    {
                        arr3[size]=arr3[size]%10;
                        arr1[i+1]=arr1[i+1] + 1;
                    }
                    size--;
                    i++;

                }
                arr3[size]=arr1[i];
                size--;
                i++;


            }
            arr3[size]=0;
            size--;
        }
    }
    else if(size2>size1)
    {
        while(size>0)
        {
            while(i<size2)
            {
                while(i<size1)
                {
                    arr3[size]=arr1[i]+arr2[i];
                    if(arr3[size]> 9)
                    {
                        arr3[size] = arr3[size]%10;
                        arr2[i+1]=arr2[i+1] + 1;
                    }
                    size--;
                    i++;

                }
                arr3[size]=0;
                arr3[size]=arr2[i];
                size--;
                i++;


            }
            arr3[size]=0;
            size--;
        }
    }
    else if(size1=size2)
    {
        while(size>0)
        {
            while(i<size1)
            {
                while(i<size2)
                {
                    arr3[size]=arr1[i]+arr2[i];
                    if(arr3[size]> 9)
                    {
                        arr3[size]=arr3[size]%10;
                        arr1[i+1]=arr1[i+1] + 1;
                    }
                    size--;
                    i++;

                }
                arr3[size]=arr1[i];
                size--;
                i++;
            }
            arr3[size]=0;
            size--;
        }

    }
}
