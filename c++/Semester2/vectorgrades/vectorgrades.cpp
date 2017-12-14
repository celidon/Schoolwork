/*
   File Name: vectorgrades.cpp
   Developer: Anthony Hansen
   Date Last Modified: 11.03.2014
   Description: The assignment was to write a program that allowed the user to 
				insert an unlimited amount of names and grades and then sort the
				names and their correct grades ascending by grade using a vector and the STL
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
	if(st1.grade!=st2.grade)
	{
		return st1.grade<st2.grade;
	}
	else
	{
		return st1.name<st2.name;
	}
}

int main()
{
	vector<StudentInfo> gradebook;
	
	StudentInfo student;
	
	
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

	return 0;
}