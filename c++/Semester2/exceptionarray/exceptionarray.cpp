/*
   File Name: exceptionarray.cpp
   Developer: Anthony Hansen
   Date Last Modified: 06.05.2014
   Description: The assignment was to write a class named CheckedArray. This
				class contains an array that functions normally but checks that
				an index is actually inside the range of the array before using
				it. If the range is out of scope, an exception of the class
				ArrayOutOfRangeError is thrown.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
class CheckedArray
{
	public:
		CheckedArray(int z){size=z; a=new T[size];}
		T& operator[](int index);
	private:
		int size;
		T *a;	
};

class ArrayOutOfRangeError
{
	public:
		ArrayOutOfRangeError(int i, int s){index=i; size=s}
		string message(){return "Invalid index of "<<index<<".\nIndex out of range of "<<size<<".\n\n";}
	private:
		int index;
		int size
};

template <class T>
T& CheckedArray<T>::operator[](int index)
{	
	try{
		if(0<=index&&index<size)
		{
			return a[index];
		}
		throw ArrayOutOfRangeError(index,size);
	}
	catch(ArrayOutOfRangeError ex)
	{
		cout<<ex.message();
		exit(1);
	}
}

int main()
{
	cout<<"Creating an integer array of size 5\n";
	CheckedArray<int> a(5);
	
	cout<<"Setting the entire array to the index number.\n";
	
	for(int i=0; i<5; i++)
	{
		a[i]=i;
	}
	
	cout<<"Printing the value located at index==3\n";
	cout<<a[3]<<endl;
	cout<<"Printing the value located at index==5\n";
	cout<<a[5]<<endl;
	return 0;
}