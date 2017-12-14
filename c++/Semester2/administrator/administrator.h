#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "salariedemployee.h"

#include <string>

using namespace std;

namespace employeessavitch
{

    class Administrator : public SalariedEmployee
    {
		private:
			string title;
			string area;
			string supervisor;
			
		public:
			Administrator();
			Administrator(string the_name, string the_ssn, string department, string supervisor, string title, double salary);
			void set_supervisor(string name);
			void set_admin();
			void print();
			void print_check();
	};	
}//employeesavitch

#endif // ADMINISTRATOR_H
