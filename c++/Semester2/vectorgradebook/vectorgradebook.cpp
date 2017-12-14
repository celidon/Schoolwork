/*
   File Name: vectorgradebook.cpp
   Developer: Anthony Hansen
   Date Last Modified: 29.04.2014
   Description: The assignment was to write a program that allowed the user to 
				insert an unlimited amount of names and grades and then sort the
				names and their correct grades ascending by name using a vector and the STL. The program would print out the gradebook along with
				the max, mn, and mean grade.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct StudentInfo
{
	string name;
	int grade;
};

bool operator <(const StudentInfo& st1, const StudentInfo& st2)
{
	if(st1.name!=st2.name)
	{
		return st1.name<st2.name;
	}
	else
	{
		return st1.grade<st2.grade;
	}
}
	

int main()
{
	vector<StudentInfo> gradebook;
	
	StudentInfo student;
	int max=0, min=100, count=0;
	double ave=0;
	
	
	cout<<"Enter 00 as the name and grade to stop entering names and grades.\n";
	cout<<"You must enter at least one name\n";
	do{
		cout<<"Please insert the student's name as you want it entered in the gradebook\n";
		getline(cin,student.name);
		cout<<"Please insert "+student.name+"'s grade as a two digit percent\n";
		cin>>student.grade;
		cin.ignore();
		gradebook.push_back(student);
	}while(student.name!="00");
	
	std::sort(gradebook.begin(), gradebook.end());
	
	cout << "The contents of the gradebook are:\n";
	for (vector<StudentInfo>::iterator it = gradebook.begin()+1; it!=gradebook.end(); it++)
	{
		cout <<it->name<<" "<<it->grade<<endl;
	}
	
	cout<<"The highest grade in the class is: ";
	for (vector<StudentInfo>::iterator it = gradebook.begin()+1; it!=gradebook.end(); it++)
	{
		if(it->grade>max)
		{
			max=it->grade;
		}
	}
	cout<<max<<endl;
	
	cout<<"The lowest grade in the class is: ";
	for (vector<StudentInfo>::iterator it = gradebook.begin()+1; it!=gradebook.end(); it++)
	{
		if(it->grade<min)
		{
			min=it->grade;
		}
	}
	cout<<min<<endl;
	cout<<"The the class average is: ";
	for (vector<StudentInfo>::iterator it = gradebook.begin()+1; it!=gradebook.end(); it++)
	{
		ave+=it->grade;
		count++;
	}
	ave/=count;
	cout<<ave<<endl;

	return 0;
}