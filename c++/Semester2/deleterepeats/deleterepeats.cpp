/*
   File Name: deleterepeats.cpp
   Developer: Anthony Hansen
   Date Last Modified: 10.04.2014
   Description: The assignment was to rewrite the delete_repeats program using
				a template for the base class. The original program goes through
				an array and deletes repeated values, shrinking the array while
				doing so. The original program was taken from the archives on boss.
Email Address: hansen.tony92@gmail.com
*/

#include<iostream>

using namespace std;
/*
   shift_left
	description: shifts the elements from the given position over one element to the "left" of the array
	parameters: char* ar - the array that has the element
	            int position - the position of the element to "delete"
					int elements - the number of elements in the array
   returns: void
*/ 
template<class baseType>
void shift_left(baseType ar[],int position,int elements)
{
	
	for(int i=position+1;i < elements;i++)
		ar[i-1] = ar[i];
}

/*
   delete_repeats
	Description: deletes repeating elements in the array
	parameters: char* ar - the array to scan
	            int elements - the number of elements in the array
   returns: the current number of elements after the delete
*/
template<class baseType>
int delete_repeats(baseType ar[],int elements)
{
	int current_size = elements;
	for(int i=0;i < current_size;i++)
		for(int j=i+1;j<current_size;j++)
			if(ar[j] == ar[i])
				shift_left(ar,j--,current_size--);
	return current_size;
}

template<class baseType>
void print_array(baseType ar[],int size)
{
	for (int i=0;i<size;i++)
		cout << ar[i] << " ";
   cout << endl;
}

int main()
{

   char a[10];
	a[0] = 'a';
	a[1] = 'a';
	a[2] = 'c';
	a[3] = 'd';
	a[4] = 'a';
	a[5] = 'f';
	a[6] = 'g';
	a[7] = 'h';
	a[8] = 'a';
	a[9] = 'a';

   int size = 10;
	cout << "Before: ";
	print_array(a,size);
	int current_size = delete_repeats(a,size);
	cout << "After: ";
	print_array(a,current_size);

	return 0;
}