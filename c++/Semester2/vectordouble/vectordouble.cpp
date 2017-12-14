/*
   File Name: vectordouble.cpp
   Developer: Anthony Hansen
   Date Last Modified: 06.03.2014
   Description: The assignment was to write a program that uses a class and
				operator assignments in order to simulate the vector library
				available. This includes overloading the assignment operator
				and creating member functions that work as pushback, reserve,
				resize, capacity, and size.
Email Address: hansen.tony92@gmail.com
*/


#include <iostream>

using namespace std;

class VectorDouble
{
    public:
        VectorDouble();
        VectorDouble(int);
        VectorDouble(const VectorDouble& other);
        ~VectorDouble();
        double value_at(int i);
        void change_value_at(double d, int i);
        friend bool operator ==(const VectorDouble& vector1, const VectorDouble& vector2);
        VectorDouble operator=(VectorDouble& other);
        void pushback(double);
        void capacity();
        void size();
        void reserve(int);
        void resize(int);
        void print();

    private:
        double *vector, *temp;
        int max_count, count;
};

VectorDouble::VectorDouble()
{
    vector = new double [50];
    for(int i=0; i<50; i++)
    {
        vector[i]=0;
    }
    max_count = 50;
    count = 0;
}

VectorDouble::VectorDouble(int size)
{
    vector = new double [size];
    for(int i=0; i<size; i++)
    {
        vector[i]=0;
    }
    max_count = size;
    count = 0;
}

VectorDouble::VectorDouble(const VectorDouble& other)
{
    vector=new double [other.max_count];

    for(int i=0; i<other.max_count; i++)
    {
        vector[i]=other.vector[i];
    }
    max_count = other.max_count;
    count = other.count;
}

VectorDouble::~VectorDouble()
{
    delete [] vector;
}

double VectorDouble::value_at(int i)
{
    return vector[i];
}

void VectorDouble::change_value_at(double d, int i)
{
    vector[i]=d;
}

bool operator ==(const VectorDouble& vector1, const VectorDouble& vector2)
{
    if(vector1.count!=vector2.count)
    {
       return false;
    }
    else
    {
        for(int i=0; i<vector1.count; i++)
        {
            if(vector1.vector[i]!=vector2.vector[i])
            {
                return false;
            }
        }
    }
}

void VectorDouble::print()
{
    for(int i=0; i<max_count; i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
}

VectorDouble VectorDouble::operator =(VectorDouble& other)
{
    vector = new double[other.max_count];
    for(int i=0; i<max_count; i++)
    {
        vector[i]=other.vector[i];
    }
    count=other.count;
    max_count=other.max_count;
}

void VectorDouble::pushback(double input)
{
    vector[count]=input;
    count++;
}

void VectorDouble::capacity()
{
    cout<<max_count;
}

void VectorDouble::size()
{
    cout<<count;
}

void VectorDouble::reserve(int new_size)
{
    temp = new double [new_size];

    for(int k=0; k<new_size; k++)
    {
        temp[k]=0;
    }

    for(int i=0; i<max_count; i++)
    {
        temp[i]=vector[i];
    }
    delete [] vector;
    vector=temp;
    max_count=new_size;
}

void VectorDouble::resize(int new_size)
{
    temp = new double [new_size];
    for(int i=0; i<new_size; i++)
    {
        temp[i]=vector[i];
    }
    delete [] vector;
    vector=temp;
    max_count=new_size;
}

int main()
{

    int where, size=20;
    VectorDouble test(size);
    double input, change;

    cout<<"An empty vector of size 20 has been made. Please fill it with positive numbers.\n";
    cout<<"Insert a negative number to stop adding values.\n";

    do{
        cin>>input;
        if(input>0)
        {
            test.pushback(input);
        }
    }while(input>0);

    cout<<"You entered ";

    test.size();

    cout<<" values.\n";

    cout<<"The vector will be copied into a new vector.\n";

    VectorDouble trial(test);

    test.print();

    cout<<"Please enter a value and at which position you want to place it.\n";
    cin>>change>>where;

    cout<<"The value in the "<<where<<" position was "<<test.value_at(where-1)<<endl;

    test.change_value_at(change,where-1);

    cout<<"The value in the "<<where<<" position is now "<<test.value_at(where-1)<<endl;

    cout<<"Both vectors have been resized and now look like this:\nVector1\n";

    test.reserve(30);

    test.print();

    cout<<"Vector2\n";

    trial.resize(10);

    trial.print();

    cout<<"The vectors will now be compared.\n";

    cout<<(test==trial ? "The vectors are equivalent":"The vectors are not equivalent")<<endl;


    return 0;
}
