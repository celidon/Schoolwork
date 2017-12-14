/*
   File Name: bankec.cpp
   Developer: Anthony Hansen
   Date Last Modified: 17.04.2014
   Description: The assignment was to use the code found at
				http://boss.vvc.edu/tonningp/cis202/examples/bank_sim.cpp
				implement a vector of bank tellers that will service the customers
				in the bank line.  Use an average service time per customer to be
				between 1 and 3 minutes.  Run the simulation for one 8 hour day,
				and print the average wait time for each client in line.
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
double ave;
double ave2;

int main()
{
	int totalcust=0;
	int waiting;
	ave=0.0;
	ave2=0.0;
	double line=0.0;
	int i=0;
	
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
	
	//line/=totalcust;
	
	totalcust=totalcust-bank_line.size();
	
	//cout<<i<<endl;
	
	//cout<<TOTAL_TIME/(totalcust*60)<<endl;
	
	//cout<<totalcust<<endl;
	
	
	
	cout<<"Average processing time per customer: "<<ave/(totalcust*60)<<" minutes.\n";
	cout<<"Average wait time per person: "<<ave2/(totalcust*60)<<" minutes.\n";
	cout<<"Average time each customer is in the bank: "<<(ave+ave2)/(totalcust*60)<<" minutes.\n";

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

/*
bool gen_customer(int time_elapsed)
{
    bool gen = false;
    int r = random() %100 + 1;
    if(time_elapsed < 14400)
    {
        if(r <= 10 ) 
            gen =  true;
    }
    else if (time_elapsed < 18000)
    {
        if(r <= 40 ) 
            gen =  true;
    }
    else if (time_elapsed < 28800)
    {
        if(r <= 30 )
            gen =  true;
    }
    return gen;
}
*/

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
			ave2+=c_cust.waitTime(ctime);//+tellers[i].getProcessTime();
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