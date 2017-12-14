/*
   File Name: gradebook.cpp
   Developer: Anthony Hansen
   Date Last Modified: 18.02.2014
   Description: The assignment was to write a program that contained a grading
                policy for a class, based on 2 quizzes, a midterm, and a final.
                The quizzes together are worth 25%, the midterm is worth 25%,
                and the final is worth 50% of the final grade. Using a structure,
                the program intakes a number of student names and their grades on
                the tests and quizzes. It then calculates the final percentage
                and assigns a letter grade. It then outputs the grade book.
   Email Address: hansen.tony92@gmail.com
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//The structure containing the student record
struct Grades{
    int quiz1, quiz2, midterm, final;
    double grade;
    string name;
    char letter;
};

void printGrades(Grades [], int);

int main()
{
    int classsize;

//By determining class size, we can use an array, allowing multiple students to be entered into the grade book
    cout<<"How many students are there?\n";
    cin>>classsize;

    Grades student[classsize];

//Input of information for each student
    for(int i=0; i<classsize; i++)
    {
        cout<<"Enter the "<<i+1<<" student's name:\n";
        cin.ignore();
        getline(cin,student[i].name);
        cout<<"Enter "<<student[i].name<<"'s score on the first quiz:\n";
        cin>>student[i].quiz1;
        cout<<"Enter "<<student[i].name<<"'s score on the second quiz:\n";
        cin>>student[i].quiz2;
        cout<<"Enter "<<student[i].name<<"'s score on the midterm:\n";
        cin>>student[i].midterm;
        cout<<"Enter "<<student[i].name<<"'s score on the final:\n";
        cin>>student[i].final;

        student[i].grade=(.25*(5*(student[i].quiz1+student[i].quiz2)))+(.25*(student[i].midterm))+(.5*(student[i].final));

        if(student[i].grade>=90)
        {
            student[i].letter='A';
        }
        else if(student[i].grade<90 && student[i].grade>=80)
        {
            student[i].letter='B';
        }
        else if(student[i].grade<80 && student[i].grade>=70)
        {
            student[i].letter='C';
        }
        else if(student[i].grade<70 && student[i].grade>=60)
        {
            student[i].letter='D';
        }
        else
        {
            student[i].letter='F';
        }
    }

    printGrades(student, classsize);

    return 0;
}

//Printing out the completed gradebook
void printGrades(Grades student[], int classsize)
{
    cout<<setw(20)<<"Name"<<setw(7)<<"Quiz 1"<<setw(7)<<"Quiz 2"<<setw(8)<<"Midterm"<<setw(6)<<"Final";
    cout<<setw(8)<<"Percent"<<setw(6)<<"Grade"<<endl;

    for(int i=0; i<classsize; i++)
    {
        cout<<setw(20)<<student[i].name<<setw(7)<<student[i].quiz1<<setw(7)<<student[i].quiz2<<setw(8)<<student[i].midterm;
        cout<<setw(6)<<student[i].final<<setw(8)<<student[i].grade<<setw(6)<<student[i].letter<<endl;
    }
}
