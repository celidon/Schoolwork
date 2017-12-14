//This is the file: doctor.cpp.
//This is the implementation for the class Doctor.
//The interface for the class Doctor is in the header file Doctor.h.

#include "doctor.h"
#include <iostream>

using namespace std;

namespace employeessavitch
{
	Doctor::Doctor() : SalariedEmployee(), specialty("No specialty declared yet"), visitfee(0)
	{
		//Deliberately empty
	}
	
	Doctor::Doctor(string the_name, string the_specialty, double the_fee)
	{
		name=the_name;
		specialty=the_specialty;
		visitfee=the_fee;		
	}
	
	Doctor::Doctor(Doctor& other)
	{
		name = other.name;
		specialty=other.specialty;
		visitfee=other.visitfee;
	}
	
	void Doctor::set_specialty()
	{
		cout<<"What is the specialty?\n";
		getline(cin, specialty);
	}
	
	void Doctor::set_visitfee()
	{
		cout<<"What is the fee per office visit?\n";
		cin>>visitfee;
	}
	
	void Doctor::set_date()
	{
		cin.ignore();
		cout<<"What is the date of your appointment?\n";
		getline(cin, date);
		
		cout<<"At what time?\n";
		getline(cin, time);
	}
	
	void Doctor::set_doctor()
	{
		cout<<"What is the doctor's name?\n";
		getline(cin, name);
		
		set_specialty();
		
		set_visitfee();
	}
	
	void Doctor::set_appointment()
	{
		set_doctor();
		
		set_date();
	}
	
	void Doctor::print_appointment()
	{
		cout<<"Doctor: "<<name<<"	";
		cout<<"Specialty: "<<specialty<<endl;
		cout<<"Date: "<<date<<"   Time: "<<time<<endl;
		cout<<"Cost: $"<<visitfee<<endl;
	}
	
	void Doctor::print_doctor()
	{
		cout<<"Doctor: "<<name<<endl;
		cout<<"Specialty: "<<specialty<<endl;
		cout<<"Office Visit Fee: $"<<visitfee<<endl;
	}
	
	Doctor Doctor::operator =(Doctor& other)
	{
		name = other.name;
		specialty=other.specialty;
		visitfee=other.visitfee;
	}
}//employeesavitch