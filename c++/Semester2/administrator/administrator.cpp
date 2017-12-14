//This is the file: administrator.cpp.
//This is the implementation for the class Administrator.
//The interface for the class Administrator is in the header file administrator.h.

#include "administrator.h"
#include <iostream>

using namespace std;

namespace employeessavitch
{
	Administrator::Administrator() : SalariedEmployee(), supervisor("No supervisor yet"), title("No title yet"), area("No department yet")
	{
		//Deliberately empty
	}
	Administrator::Administrator(string the_name, string the_ssn, string department, string supervisor, string title, double salary)
				:SalariedEmployee(the_name, the_ssn, salary), supervisor(supervisor), title(title), area(department)
	{
		//Deliberately empty
	}
	void Administrator::set_supervisor(string name)
	{
		supervisor=name;
	}
	void Administrator::set_admin()
	{
		cout<<"What is the person's name?\n";
		getline(cin, name);
		
		cout<<"What is the person's title?\n";
		getline(cin,title);
		
		cout<<"What is the person's department?\n";
		getline(cin,area);
		
		cout<<"Who is the person's supervisor?\n";
		getline(cin,supervisor);
		
		cout<<"What is the person's SSN?\n";
		getline(cin,ssn);
		
		cout<<"What is the person's salary?\n";
		cin>>salary;
	}
	void Administrator::print()
	{
		cout<<"Administrator: "<<name<<endl;
		cout<<"Social Security Number: "<<ssn<<endl;
		cout<<"Title: "<<title<<" of "<<area<<endl;
		cout<<"Supervisor: "<<supervisor<<endl;
		cout<<"Annual Salary: $"<<salary<<endl;
	}
	void Administrator::print_check()
    {
        set_net_pay(salary);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << get_name() << endl;
        cout << "The sum of " << get_net_pay() << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << get_ssn() << endl;
        cout << title <<" of "<<area<<" under "<<supervisor<<endl;
		cout<< "Regular Pay: $"<<salary<<endl;
        cout << "_________________________________________________\n";
    }
}//employeesavitch