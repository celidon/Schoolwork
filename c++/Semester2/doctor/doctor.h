//This is the header file doctor.h.
//This is the interface for the class Doctor.

#ifndef DOCTOR_H
#define DOCTOR_H
#include "salariedemployee.h"

#include <string>

using namespace std;

namespace employeessavitch
{

    class Doctor : public SalariedEmployee
    {
		private:
			string specialty;
			double visitfee;
			string date, time;
			
		public:
			Doctor();
			Doctor(string the_name, string specialty, double visitfee);
			Doctor(Doctor& other);
			void set_date();
			void set_specialty();
			void set_visitfee();
			void set_doctor();
			void set_appointment();
			void print_appointment();
			void print_doctor();
			Doctor operator =(Doctor& other);
	};	
}//employeesavitch

#endif // DOCTOR_H
