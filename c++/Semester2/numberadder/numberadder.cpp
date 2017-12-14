/*
   File Name: numberadder.cpp
   Developer: Anthony Hansen
   Date Last Modified: 06.02.2014
   Description: Upload the program that was outlined in class.
                1. Prompt user for size of the arrays.
                2. Interactively ask the user for elements for the 1st and
                   then the 2nd array.
                3. Add the elements together and place them in a third array.
                4. Print out the 3rd array.
                5. Use functions to accomplish this program assignment.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

void program();
char checkNum(char [], int);
void reverseArray(int [], char [], int);
void printArray(int [], int);
void zeroArray(int [], int);
void addArray(int [], int [], int [], int);

int main()
{

    char ans;

    do{
        cout<<"Would you like to add two numbers? y/n\n";
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
//Where everything happens to keep main() cleaner
void program()
{
    int Size;
    char ans;

    cout<<"How large are the numbers?\n";
    cin>>Size;

    char num1[Size], num2[Size];

    cout<<"Do not insert a number larger than "<<Size<<" digits\n";
    cout<<"If you do, only the first "<<Size<<" numbers will be used.\n";

    cout<<"Do not insert a number shorter than "<<Size<<" digits\n";
    cout<<"Doing so will result in an error saying: 'That is not a number'\n";

    do{
        cout<<"Please input the first number:\n";
        cin>>num1;
        ans=checkNum(num1, Size);
    }while(ans=='n');

    do{
        cout<<"Please input the second number:\n";
        cin>>num2;
        ans=checkNum(num2, Size);
    }while(ans=='n');

    int arr1[Size], arr2[Size], arr3[Size+1];

    reverseArray(arr1, num1, Size);
    reverseArray(arr2, num2, Size);

    zeroArray(arr3, Size+1);

    addArray(arr1, arr2, arr3, Size);

    printArray(arr3, Size+1 );

}
//checking that all the characters entered are numbers
char checkNum(char arr[], int numsize)
{
    int i=0;
    char ans;

    while(i<numsize)
    {
        int current=static_cast<int>(arr[i]);

        if(current>=48 && current<=57)
        {
           ans = 'y';
           i++;
        }
        else
        {
            cout<<"That is not a number\n";
            ans = 'n';
            break;
        }
    }

    return ans;
}
//reversing the arrays for easier addition
void reverseArray(int arr[], char ary[], int size)
{

    int i, count = size;

    for(i = 0; i < size; i++)
    {
        count--;
        arr[count] = ary[i]-48;
    }
}
//Printing an integer array
void printArray(int arr[], int size)
{
    for(int i = size-1; i>=0; i--)
    {
        cout<<arr[i];
    }
    cout<<endl;
}
//Filling an array with 0 initially in order to avoid errors while adding
void zeroArray(int arr[], int size)
{
    int i;

    for(i = 0; i < size+1; i++)
    {
        arr[i] = 0;
    }
}
//Adding the arrays
void addArray(int arr1[], int arr2[], int arr3[], int size)
{

    for(int i=0; i<size; i++)
    {
        arr3[i]=arr1[i]+arr2[i];
    }
    //Taking the sum array and finishing the addition by making certain each part
    //of the array is less than 9
    for(int j=0; j<size+1; j++)
    {
        if(arr3[j]>9)
        {
            arr3[j]=arr3[j]%10;
            arr3[j+1]=arr3[j+1]+1;
        }
    }
}
