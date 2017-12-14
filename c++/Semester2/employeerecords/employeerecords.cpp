/*
   File Name: gradebook.cpp
   Developer: Anthony Hansen
   Date Last Modified: 20.02.2014
   Description: The assignment was to write a a definition for a structure
                type for records consisting of a person’s wage rate, accrued
                vacation (in whole days), and status (hourly or salaried).
                Represent the status as one of the two character values ‘H’
                and ‘S’. Call the type EmployeeRecord.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//The structure containing the employee record
struct EmployeeRecord{
    int vacationdays, idnum;
    double wage;
    string name;
    char status;
};

void printRecords(EmployeeRecord [], int);

int main()
{
    int employment;

//By determining class size, we can use an array, allowing multiple employees to be entered into the grade book
    cout<<"How many people are employed?\n";
    cin>>employment;

    EmployeeRecord employee[employment];

//Input of information for each employee
    for(int i=0; i<employment; i++)
    {
        cout<<"Enter the "<<i+1<<" employee's name:\n";
        cin.ignore();
        getline(cin,employee[i].name);
        cout<<"Enter "<<employee[i].name<<"'s 9 digit ID number:\n";
        cin>>employee[i].idnum;
        cout<<"Enter "<<employee[i].name<<"'s wage rate in dollars:\n";
        cin>>employee[i].wage;
        cout<<"Enter "<<employee[i].name<<"'s number of accrued vacation days:\n";
        cin>>employee[i].vacationdays;
        cout<<"Enter "<<employee[i].name<<"'s status(H for hourly or S for Salary):\n";
        cin>>employee[i].status;
    }

    printRecords(employee, employment);

    return 0;
}

//Printing out the records
void printRecords(EmployeeRecord employee[], int employment)
{
    cout<<setw(9)<<"ID"<<setw(20)<<"Name"<<setw(11)<<"Wage"<<setw(9)<<"Vacation"<<setw(7)<<"Status"<<endl;

    for(int i=0; i<employment; i++)
    {
        cout<<setw(9)<<employee[i].idnum<<setw(20)<<employee[i].name<<setw(2)<<"$"<<setw(9)<<employee[i].wage;
        cout<<setw(4)<<employee[i].vacationdays<<" days"<<setw(4)<<employee[i].status<<endl;
    }
}
