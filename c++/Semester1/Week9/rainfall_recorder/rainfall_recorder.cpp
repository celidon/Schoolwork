/*
File Name: rainfall_recorder.cpp
Developer: Anthony Hansen
Date Last Modified: 11.11.2013
Description: The assignment was to write a program that opens two data files
             of type double, uses them to fill arrays, and then outputs the
             data collected in a table and a graph, sent to files of the user's
             choice.
Email Address: hansen.tony92@gmail.com
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

void fillArray(ifstream&, double [], int);
void deltalist(double [], double [], double [], int);
void printArray(ofstream&, double [], int);
void table(ofstream&, double[], double [], double [], int);
void graph(ofstream&, double[], double [], int);
void scale(double [], double [], int);
void printAstrisks(ofstream&, int);
int rounder(double);

int main()
{
    int arrsize;
    ifstream infile, infile2;
    ofstream fout1, fout2;
    string t, g;

    infile.open("rainfall_previous.dat");
    infile2.open("rainfall_current.dat");

    cout<<"Please enter the name of the file you would like to create to hold the table:\n";
    cin>>t;

    cout<<"Please enter the name of the file you would like to create to hold the graph:\n";
    cin>>g;

    fout1.open((string(t).c_str()));
    fout2.open(string(g).c_str());

    arrsize = 12;

    double arr1[arrsize], arr2[arrsize], arr3[arrsize];


    fillArray(infile, arr1, arrsize);
    fillArray(infile2, arr2, arrsize);

    deltalist(arr1, arr2, arr3, arrsize);

    table(fout1, arr1, arr2, arr3, arrsize);

    graph(fout2, arr1, arr2, arrsize);

    infile.close();
    infile2.close();
    fout1.close();
    fout2.close();

    return 0;
}
//Graph ofout<<"Jan\nAverage: "<<outgraph(arr1[0])<<endl<<"Actual: "<<outgraph(arr2[0])<<endl;utput
void graph(ofstream& fout, double arr1[], double arr2[], int size)
{
    double arr3[size], arr4[size];
    string month[size];
    month[0]="Jan";
    month[1]="Feb";
    month[2]="Mar";
    month[3]="Apr";
    month[4]="May";
    month[5]="Jun";
    month[6]="July";
    month[7]="Aug";
    month[8]="Sep";
    month[9]="Oct";
    month[10]="Nov";
    month[11]="Dec";

    scale(arr1, arr3, size);
    scale(arr2, arr4, size);


    fout<<"For the graphs, each '*' is equal to .02 inches of rain.\n"<<endl;

    for(int i=0; i<size; i++)
    {
        fout<<month[i]<<endl<<"Average: ";
        printAstrisks(fout, arr3[i]);
        fout<<"Actual: ";
        printAstrisks(fout, arr4[i]);
        fout<<endl;
    }
}

int rounder(double number)
{
    return static_cast<int>(floor(number+.5));
}

void scale(double arr[], double arr1[], int size)
{
    for(int i=0; i<size; i++)
    {
        arr1[i]=(rounder(arr[i]/.02));
    }
}

void printAstrisks(ofstream& fout, int number)
{
    for(int i=1; i<=number; i++)
    {
        fout<<"*";
    }
    fout<<endl;
}

//Table ouptput
void table(ofstream& fout, double arr1[], double arr2[], double arr3[], int arrsize)
{
    if (fout.fail())
    {
        cout<<"Input file opening failed.\n";
        exit(1);
    }

    string month1="Jan";
    string month2="Feb";
    string month3="Mar";
    string month4="Apr";
    string month5="May";
    string month6="Jun";
    string month7="Jul";
    string month8="Aug";
    string month9="Sep";
    string month10="Oct";
    string month11="Nov";
    string month12="Dec";

    fout<<"  Month   ||  "<<month1<<" | "<<month2<<" | "<<month3<<" | "<<month4<<" | ";
    fout<<month5<<" | "<<month6<<" | "<<month7<<" | "<<month8<<" | ";
    fout<<month9<<" | "<<month10<<" | "<<month11<<" | "<<month12<<" |";
    fout<<endl;
    fout<<"  Actual  || ";
    printArray(fout, arr2, arrsize);
    fout<<endl<<"  Average || ";
    printArray(fout, arr1,arrsize);
    fout<<endl<<"Difference|| ";
    printArray(fout, arr3, arrsize);

}

//Printing out an array
void printArray(ofstream& fout, double arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        fout<<setw(5)<<arr[i]<<"|";
    }
}

void fillArray(ifstream& infile, double arr[], int size)
//Filling an array from a file
{
    int i = 0;
    double next;

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
}

//Finding the difference between each value and the average
void deltalist(double arr[], double arr2[], double ary[], int size)
{

    int i = 0;

    while(i < size)
    {
        ary[i] = (arr2[i] - arr[i]);
        i++;
    }
}
