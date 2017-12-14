/*
   File Name: searcharrtemp.cpp
   Developer: Anthony Hansen
   Date Last Modified: 10.04.2014
   Description: The assignment was to write a template that searches a partially
				filled array with for a specified value. If the value is found,
				the template function returns the index where it is found at.
				If it is not found, the index is declared to be -1.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>

using namespace std;

template<class baseType>
int searchArr(baseType arr[], int size, baseType val)
{
	bool found=false;
	int index=-1;
	
	for(int i=0; i<size; i++)
	{
		if(arr[i]==val)
		{
			found=true;
			index=i;
			break;
		}
	}
	
	return index;
}

template<class baseType>
void printArr(baseType arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main()
{	
	cout<<"Two arrays of different types have been initialized.\n";
	cout<<"They will be searched for values and the index returned.\n";
	cout<<"If the index is -1, the value is not present in the array.\n";

	int arr1[10]={1,2,3,4,5,6,7,8,9,0};
	char arr2[13]={'a','b','b','d','e','f','g','h','i','j'};
	
	cout<<"Integer Array of size 10:\n";
	printArr(arr1, 10);
	cout<<"\nCharacter Array of size 13:\n";
	printArr(arr2, 13);
	
	cout<<"Integer Array searching for '5'. Index: "<<searchArr(arr1, 10, 5)<<endl;
	cout<<"Character Array searching for 'c'. Index: "<<searchArr(arr2, 13, 'c')<<endl;
	
	return 0;
}