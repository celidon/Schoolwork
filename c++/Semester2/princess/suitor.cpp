//This is the file: suitor.cpp.
//This is the implementation for the class Suitor.
//The interface for the class Suitor is in the header file suitor.h.

#include <iostream>
#include "suitor.h"

using namespace std;

Suitor::Suitor()
{
	number=1;
	
}

Suitor::Suitor(int i)
{
	number=i;
}

void Suitor::input(int s)
{
	Suitor *tmp;
	
	head=new Suitor();
	head->link=head;
	
	for(int i=s; i>1; i--)
	{
		tmp=new Suitor(i);
		tmp->link=head->link;
		head->link=tmp;
	}
}

void Suitor::deleteSuitor()
{
	cout<<head->link->number<<" Eliminated\n";
	head->link=head->link->link;	
}

void Suitor::suitorPicker(int namelen)
{
	int i=1;
	
	do{	
		if(((i+1)%namelen)==0)
		{
			deleteSuitor();
			i++;
		}
		head=head->link;
		i++;
	}while(head->number!=head->link->number);
	
	cout<<"Suitor "<<head->number<<" will marry the princess!\n";
	
}