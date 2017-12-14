/*
File Name: stddev.cpp
Developer: Anthony Hansen
Date Last Modified: 3.11.2013
Description: The assignment was to write a program that takes the standard deviation
             of a list of numbers or type double found in a file using arrays.
Email Address: hansen.tony92@gmail.com
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>


double average(double [], int);
void deltalist(double [], double [], double, int);
void squarelist(double [], double [], int size);
void stddev(double [], double [], int);
void fillArray(double [], int);
int sizeFile();

using namespace std;

int main()
{
    int size;

    size = sizeFile();

    double a[size], b[size];

    fillArray(a, size);

    stddev(a, b, size);

    return 0;
}

//Finding the average value of an array
double average(double arr[], int size)
{
    double sum = 0, ave;
    int i=0;

    while(i < size)
    {
        sum = sum + arr[i];
        i++;
    }

    ave = sum/(size);

    return ave;
}

//Finding the difference between each value and the average
void deltalist(double arr[], double ary[], double ave, int size)
{

    int i = 0;

    while(i < size)
    {
        ary[i] = (arr[i] - ave);
        i++;
    }
}

//Squaring all values
void squarelist(double arr[], double ary[], int size)
{
    int i=0;

    while(i < size)
    {
        arr[i] = ary[i] * ary[i];
        i++;
    }
}

//Calling all the necessary functions and actual finding the standard deviation
void stddev(double arr[], double ary[], int size)
{
    double sum=0;
    double stddev;

    int i = 0;

    double ave=average(arr, size);
    deltalist(arr, ary, ave, size);
    squarelist(arr, ary, size);

    while(i < size)
    {
        sum = sum + arr[i];
        i++;
    }

    stddev = sqrt(sum/(size));

    cout<<"The standard deviation of the numbers in the file 'stddev.dat' is: "<<stddev<<endl;
}


//Filling an array from a file
void fillArray(double arr[], int size)
{
    int i = 0;
    ifstream infile;
    double next;

    infile.open("stddev.dat");

    if (infile.fail())
    {
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    while(infile >> next)
    {
        arr[i] = next;
        i++;
    }

    infile.close();
}


//Determinig the size of the file so that the arrays would be the correct size
//and the size would be editable by simply changing the file.
int sizeFile()
{
    int i = 0;
    ifstream infile;
    double next;

    infile.open("stddev.dat");

    if (infile.fail())
    {
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    while(infile >> next)
    {
        i++;
    }

    infile.close();

    return i;
}
