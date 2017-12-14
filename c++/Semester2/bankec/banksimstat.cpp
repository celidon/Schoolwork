/*
   File Name: bankec.cpp
   Developer: Anthony Hansen
   Date Last Modified: 17.04.2014
   Description: The assignment was to use the code found at
				http://boss.vvc.edu/tonningp/cis202/examples/bank_sim.cpp and
				do the following:

					1)Implement counters to track the average wait time in the
					  line for the customers
					2)Output the longest and shortest wait times.
					3)Implement counters for the bank teller processing time to
					  find the average processing time for each bank teller, the
					  average for all the tellers, the longest and shortest times
					  per teller, and the longest and shortest times for all of
					  the tellers.
   Email Address: hansen.tony92@gmail.com
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>

using namespace std;


class Customer
{
	public:
        Customer() {};
		Customer(int);
        int getTime();
        int waitTime(int);
    private:
	    int time_in;
};

Customer::Customer(int t)
{
	time_in = t;
}

int Customer::getTime()
{
    return time_in;
}

int Customer::waitTime(int ctime)
{
    return ctime - time_in;
}

class Teller
{
    public:
        Teller();
        void setCustomer(Customer);
        void releaseCustomer();
        bool hasCustomer();
        bool processed(int);
        void setProcessTime(int);
		int getProcessTime();
    private:
        Customer currentCustomer;
        bool processing;
        int process_time;
};

Teller::Teller()
{
    processing = false;
}

void Teller::setCustomer(Customer c)
{
    currentCustomer = c;
    processing = true;
}

void Teller::releaseCustomer()
{
    if (processing)
        processing = false;
}

bool Teller::hasCustomer()
{
    return processing;
}

bool Teller::processed(int currentTime)
{
    return (currentTime - currentCustomer.getTime()) >= process_time;
}

void Teller::setProcessTime(int tp)
{
    process_time = tp;
}

int Teller::getProcessTime()
{
	return process_time;
}

bool gen_customer(int);
void print_array(int* c);
void process_line(list<Customer>&,vector<Teller>&,int);
void print_list(list<Customer>);

const double TOTAL_TIME=60*60*8;
const int TELLERS=4;
double ave, ave2, custwaitmax, custwaitmin;
double bt1pt, bt1c, bt2pt, bt2c, bt3pt, bt3c, bt4pt, bt4c;
double bt1max, bt1min, bt2max, bt2min, bt3max, bt3min, bt4max, bt4min, btmax, btmin;

int main()
{
	int totalcust=0;
	int waiting;
	ave=0.0;
	ave2=0.0;
	double line=0.0;
	int i=0;
	bt1max=0;
	bt1min=180;
	bt2max=0;
	bt2min=180;
	bt3max=0;
	bt3min=180;
	bt4max=0;
	bt4min=180;
	bt1c=0;
	bt2c=0;
	bt3c=0;
	bt4c=0;
	bt1pt=0;
	bt2pt=0;
	bt3pt=0;
	bt4pt=0;
	
	
    cout << time(0) << endl;
    srand(time(0));
	list<Customer> bank_line;
    vector<Teller> tellers;
    for(int i=0;i<TELLERS;i++)
        tellers.push_back(Teller());
	for(int time_elapsed=0;time_elapsed<TOTAL_TIME;time_elapsed++)
	{
        if(gen_customer(time_elapsed))
        {
            bank_line.push_back(Customer(time_elapsed));
            print_list(bank_line);
			totalcust++;
			line+=bank_line.size();
        }
        process_line(bank_line,tellers,time_elapsed);
		i++;
	}
	cout << "after " <<  (TOTAL_TIME/60/60) <<   " hours there are " << bank_line.size() << " customers in the line" << endl;	
    print_list(bank_line);
	
	totalcust=totalcust-bank_line.size();	
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout<<"Average time each customer is in the bank: "<<(ave+ave2)/(totalcust*60)<<" minutes.\n";
	cout<<"Average time each customer waited in line: "<<ave2/(totalcust*60)<<" minutes.\n";
	cout<<"Average processing time per customer for all tellers: "<<ave/(totalcust*60)<<" minutes.\n";
	
	cout<<"Average processing time per customer for teller 1: "<<bt1pt/(bt1c*60)<<" minutes.\n";
	cout<<"Average processing time per customer for teller 2: "<<bt2pt/(bt2c*60)<<" minutes.\n";
	cout<<"Average processing time per customer for teller 3: "<<bt3pt/(bt3c*60)<<" minutes.\n";
	cout<<"Average processing time per customer for teller 4: "<<bt4pt/(bt4c*60)<<" minutes.\n";
	
	cout<<"Maximum processing time for teller 1: "<<bt1max/60<<" minutes.\n";
	cout<<"Minimum processing time for teller 1: "<<bt1min/60<<" minutes.\n";
	cout<<"Maximum processing time for teller 2: "<<bt2max/60<<" minutes.\n";
	cout<<"Minimum processing time for teller 2: "<<bt2min/60<<" minutes.\n";
	cout<<"Maximum processing time for teller 3: "<<bt3max/60<<" minutes.\n";
	cout<<"Minimum processing time for teller 3: "<<bt3min/60<<" minutes.\n";
	cout<<"Maximum processing time for teller 4: "<<bt4max/60<<" minutes.\n";
	cout<<"Minimum processing time for teller 4: "<<bt4min/60<<" minutes.\n";
	
	if(bt1max>=bt2max&&bt1max>=bt3max&&bt1max>=bt4max)
	{
		btmax=bt1max;
	}
	else if(bt2max>=bt1max&&bt2max>=bt3max&&bt2max>=bt4max)
	{
		btmax=bt2max;
	}
	else if(bt3max>=bt1max&&bt3max>=bt2max&&bt3max>=bt4max)
	{
		btmax=bt3max;
	}
	else if(bt4max>=bt1max&&bt4max>=bt3max&&bt2max>=bt2max)
	{
		btmax=bt2max;
	}
	
	if(bt1min>=bt2min&&bt1min>=bt3min&&bt1min>=bt4min)
	{
		btmin=bt1min;
	}
	else if(bt2min>=bt1min&&bt2min>=bt3min&&bt2min>=bt4min)
	{
		btmin=bt2min;
	}
	else if(bt3min>=bt1min&&bt3min>=bt2min&&bt3min>=bt4min)
	{
		btmin=bt3min;
	}
	else if(bt4min>=bt1min&&bt4min>=bt3min&&bt2min>=bt2min)
	{
		btmin=bt2min;
	}
	
	cout<<"Maximum processing time out of all tellers: "<<btmax/60<<" minutes.\n";
	cout<<"Minimum processing time out of all tellers: "<<btmin/60<<" minutes.\n";

	return 0;
}

bool gen_customer(int time_elapsed)
{
    bool gen = false;
    int r = rand() %100 + 1;
    if(time_elapsed < 14400)
    {
        if(time_elapsed % 180 == 0 &&  r <= 70  || 
          time_elapsed % 120 == 0 &&  r <= 60  ||
          time_elapsed % 60 == 0 &&   r <= 50  ||
          r < 6  
        ) 
            gen =  true;
    }
    else if (time_elapsed < 18000)
    {
        if(time_elapsed % 180 == 0 &&  r <= 90  || 
          time_elapsed % 120 == 0 &&  r <= 80  ||
          time_elapsed % 60 == 0 &&   r <= 70  ||
          r < 6  
        ) 
            gen =  true;
    }
    else if (time_elapsed < 28800)
    {
        if(time_elapsed % 180 == 0 &&  r <= 80  || 
          time_elapsed % 120 == 0 &&  r <= 70  ||
          time_elapsed % 60 == 0 &&   r <= 60  ||
          r < 6  
        ) 
            gen =  true;
    }
    return gen;
}

void print_array(int* c)
{
	for (int i =0;i<6;i++)
		cout << "i=" << i << " - " << c[i] << endl;
}


void process_line(list<Customer>& bankline,vector<Teller>& tellers,int ctime)
{
    Customer c_cust;
    for(int i=0;i<TELLERS;i++)
    {
        if(bankline.size() != 0 && !tellers[i].hasCustomer())
        {
            int r = rand() % 120 + 60;  // this will give a time between
            c_cust = bankline.front();
            tellers[i].setCustomer(c_cust);
            tellers[i].setProcessTime(r);
			ave+=tellers[i].getProcessTime();
			ave2+=c_cust.waitTime(ctime);
			
			if(i==0)
			{
				bt1pt+=tellers[i].getProcessTime();
				bt1c++;
				if(tellers[i].getProcessTime()>bt1max&&tellers[i].getProcessTime()<=180)
				{
					bt1max=tellers[i].getProcessTime();
				}
				if(tellers[i].getProcessTime()<bt1min&&tellers[i].getProcessTime()>=60)
				{
					bt1min=tellers[i].getProcessTime();
				}
			}
			if(i==1)
			{
				bt2pt+=tellers[i].getProcessTime();
				bt2c++;
				if(tellers[i].getProcessTime()>bt2max&&tellers[i].getProcessTime()<=180)
				{
					bt2max=tellers[i].getProcessTime();
				}
				if(tellers[i].getProcessTime()<bt2min&&tellers[i].getProcessTime()>=60)
				{
					bt2min=tellers[i].getProcessTime();
				}
			}
			if(i==2)
			{
				bt3pt+=tellers[i].getProcessTime();
				bt3c++;
				if(tellers[i].getProcessTime()>bt3max&&tellers[i].getProcessTime()<=180)
				{
					bt3max=tellers[i].getProcessTime();
				}
				if(tellers[i].getProcessTime()<bt3min&&tellers[i].getProcessTime()>=60)
				{
					bt3min=tellers[i].getProcessTime();
				}
			}
			if(i==3)
			{
				bt4pt+=tellers[i].getProcessTime();
				bt4c++;
				if(tellers[i].getProcessTime()>bt4max&&tellers[i].getProcessTime()<=180)
				{
					bt4max=tellers[i].getProcessTime();
				}
				if(tellers[i].getProcessTime()<bt4min&&tellers[i].getProcessTime()>=60)
				{
					bt4min=tellers[i].getProcessTime();
				}
			}
			
            //cout << "adding customer, bankline size = " << bankline.size()<< endl;
            bankline.pop_front();
			
        }

        if(tellers[i].hasCustomer() && tellers[i].processed(ctime))
            tellers[i].releaseCustomer();
    }
}
void print_list(list<Customer> lc)
{
   list<Customer>::iterator p;
   if (lc.size() == 0)
   {
       cout << "empty" << endl;
       return;
   }
   for (p=lc.begin(); p != lc.end(); p++)
      //cout << (*p).getTime() << " ";
      cout << "*";
   cout << endl;
}