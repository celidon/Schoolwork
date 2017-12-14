/*
   File Name: midterm.cpp
   Developer: Anthony Hansen
   Date Last Modified: 25.03.2014
   Description: 1)Modify Car.cpp so that it also inherits from a class called
				  Vehicle, placing appropriate member functions in Vehicle (that
				  is, make up some member functions). Add a nondefault constructor
				  to Vehicle, which you must call inside Car’s constructor. (15
				  points)
				2)Create two classes, A and B, with default constructors that
				  announce themselves. Inherit a new class called C from A, and
				  create a member object of B in C, but do not create a constructor
				  for C. Create an object of class C and observe the results. (15
				  points)
				3)Create a three-level hierarchy of classes with default
				  constructors, along with destructors, both of which announce
				  themselves to cout. Verify that for an object of the most
				  derived type, all three constructors and destructors are
				  automatically called. Explain the order in which the calls are
				  made. (15 points)
				
				All the problems are in their own comment blocks so that all that
				needs to be done is deleting the multiline comment identifier at
				each end and compile and run, replacing the block before the next
				problem.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <string>

using namespace std;

/*//1)
class Engine
{
 
public: 
void start() const {}; 
void rev() const {}; 
void stop() const {} 
}; 

class Wheel
{
public: 
void inflate(int psi) const {}
};

class Window
{
public:
 void rollup() const {}; 
 void rolldown() const {}
};

class Door
{ 
public:
 Window window; 
 void open() const {};
 void close() const {}
};

class Vehicle
{
public:
 Vehicle();
 Vehicle(string col):colour(col){};
private:
 string colour;
};

class Car:public Vehicle
{
public:
 Car() {};
 Car(string tone):Vehicle(tone){};
 Engine engine;
 Wheel wheel[4];
 Door left, right; 
// 2-door
};

int
 main()
{
 Car car("black");
 car.left.window.rollup();
 car.wheel[0].inflate(72);
}*/
 
/*
//2)
class A
{
	public:
	A() {cout<<"A constructor\n";};
};

class B
{
	public:
	B() {cout<<"B constructor\n";};
};

class C:public A
{
	B b;
};

int main()
{
	C c;
	return 0;
}

/*
Output:
	A constructor
	B constructor
*/*/

/*
//3)
class A
{
	public:
	A() {cout<<"A constructor\n";};
	~A() {cout<<"A destructor\n";};
};

class B:public A
{
	public:
	B() {cout<<"B constructor\n";};
	~B() {cout<<"B destructor\n";};
};

class C:public B
{
	public:
	C() {cout<<"C constructor\n";};
	~C() {cout<<"C destructor\n";};
};

int main()
{
	C c;
	return 0;
}

/*
Output:
	A constructor
	B constructor
	C constructor
	C destructor
	B destructor
	A destructor
	
Explaination:
	The constructors were called from the base class to the most derived class
	because the base class contains an object that becomes the child class' 
	object. This is repeated because C is the child of B. This is reversed for
	the destructors because an object can't be destroyed until after the derived
	objects have been deleted
*/*/