//This is the file: polynomial.cpp.
//This is the implementation for the class Polynomial.
//The interface for the class Polynomial is in the header file polynomial.h.

#include <iostream>
#include "polynomial.h"
#include <cmath>

using namespace std;

Polynomial::Polynomial()
{
	coef=0;
	exp=0;
	link=NULL;
}
Polynomial::Polynomial(Polynomial& other)
{
	Polynomial *head, *tmp;
	head=other.link;
	link=NULL;
	
	while(head!=NULL)
	{
		tmp=new Polynomial(head->coef,head->exp);
		tmp->link=link;
		link=tmp;
		head=head->link;
	}
}
Polynomial::Polynomial(int A)
{
	coef=A;
	link=NULL;
}
Polynomial::Polynomial(int A, int power)
{
	coef=A;
	exp=power;
	link=NULL;
}

Polynomial::~Polynomial()
{
	delete link;
}

void Polynomial::input()
{
	Polynomial *tmp;
	
	char x, upcarrot;
	
	cout<<"Please enter a polynomial you wish to manipulate in the form ax^b,\nwith b in decreasing order\n";
	cout<<"Simply enter something of the form ax^0 to act as the final variable.\n";
	
	do
	{
		cin>>coef>>x>>upcarrot>>exp;
		
		if(x=='x'&&upcarrot=='^')
		{
			tmp=new Polynomial(coef,exp);
			tmp->link=link;
			link=tmp;
		}
		else
		{
			cout<<"Invalid entry\n";
		}
	}while(tmp->exp!=0);
	
}

void Polynomial::output()
{		
	Polynomial *head;
	
	head=link;
	
	if(head->exp!=0)
	{
		cout<<head->coef<<"x^"<<head->exp;
	}
	else if(head->exp==0)
	{
		cout<<head->coef;
	}
	head=head->link;
	
	while(head!=NULL)
	{
		if(head->exp!=0&&head->coef>=0)
		{
			cout<<" + "<<abs(head->coef)<<"x^"<<head->exp;
		}
		else if(head->exp!=0&&head->coef<0)
		{
			cout<<" - "<<abs(head->coef)<<"x^"<<head->exp;
		}
		else if(head->exp==0&&head->coef<0)
		{
			cout<<" - "<<abs(head->coef);
		}
		else if(head->exp==0&&head->coef>=0)
		{
			cout<<" + "<<abs(head->coef);
		}
		head=head->link;
	}
	cout<<endl;
}

void Polynomial::evalPoly()
{
	Polynomial *head;
	int x, sum=0;
	
	cout<<"By what value of x do you wish to evaluate?\n";
	cin>>x;
	
	head=link;
	
	while(head!=NULL)
	{
		sum=sum+((head->coef)*pow(x,head->exp));
		head=head->link;
	}
	
	cout<<sum<<endl;
}

void Polynomial::addPoly(Polynomial& first,Polynomial& other)
{
	Polynomial added;
	
	added=first+other;
}

Polynomial operator+(Polynomial& first, Polynomial& second)
{
	Polynomial *h1, *h2, *tmp, added, ret, fcopy(first), scopy(second);
	char ans;
	//If the user input the numbers as instructed, they will be presorted
	//These if else statements make it so they face the same direction
	//Without this, the rest of the algorithm would be a mess
	if(first.exp==0)
	{
		h1=first.link;
	}
	else
	{
		h1=fcopy.link;
	}
	
	if(second.exp==0)
	{
		h2=second.link;
	}
	else
	{
		h2=scopy.link;
	}	
	
	//While there are still values available
	while(h1!=NULL&&h2!=NULL)
	{
		//Equal exponents add
		if(h1->exp==h2->exp)
		{
			tmp=new Polynomial((h1->coef+h2->coef),h1->exp);
			tmp->link=added.link;
			added.link=tmp;
			h1=h1->link;
			h2=h2->link;
		}
		//Unequal, the smaller is put in the list and the larger saved
		else if(h1->exp>h2->exp)
		{
			tmp=new Polynomial((h2->coef),h2->exp);
			tmp->link=added.link;
			added.link=tmp;
			h2=h2->link;
		}
		else if(h2->exp>h1->exp)
		{
			tmp=new Polynomial((h1->coef),h1->exp);
			tmp->link=added.link;
			added.link=tmp;
			h1=h1->link;
		}
		//Extra variables passed to the new list
		if(h1==NULL&&h2!=NULL)
		{
			tmp=new Polynomial((h2->coef),h2->exp);
			tmp->link=added.link;
			added.link=tmp;
			h2=h2->link;
		}
		else if(h2==NULL&&h1!=NULL)
		{
			tmp=new Polynomial((h1->coef),h1->exp);
			tmp->link=added.link;
			added.link=tmp;
			h1=h1->link;
		}
		
	}
	//Output of added lists
	added.output();
	//Evaluation option
	cout<<"Would you like to evaluate it? (y/n)\n";
	do{
        cin>>ans;
        if(ans=='y' || ans=='Y')
        {
            added.evalPoly();
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
        }
		cout<<"Would you like to evaluate again? (y/n)\n";
    }while(ans!='n');
	
	//Equivalent of return 0. Because operators need to return something,
	//but return the actual addition caused breaking
	//Most likely due to the lack of an overloaded assignment operator
	return ret;

}

void Polynomial::subPoly(Polynomial& first,Polynomial& other)
{
	Polynomial subtract;
	
	subtract=first-other;
}
//Same as addition operator only with subtraction of equal exponents rather than addition
Polynomial operator-(Polynomial& first, Polynomial& second)
{
	Polynomial *h1, *h2, *tmp, subtract, ret, fcopy(first), scopy(second);
	char ans;
	
	if(first.exp==0)
	{
		h1=first.link;
	}
	else
	{
		h1=fcopy.link;
	}
	
	if(second.exp==0)
	{
		h2=second.link;
	}
	else
	{
		h2=scopy.link;
	}	
	
	while(h1!=NULL&&h2!=NULL)
	{
		if(h1->exp==h2->exp)
		{
			tmp=new Polynomial((h1->coef-h2->coef),h1->exp);
			tmp->link=subtract.link;
			subtract.link=tmp;
			h1=h1->link;
			h2=h2->link;
		}
		else if(h1->exp>h2->exp)
		{
			tmp=new Polynomial((-1)*(h2->coef),h2->exp);
			tmp->link=subtract.link;
			subtract.link=tmp;
			h2=h2->link;
		}
		else if(h2->exp>h1->exp)
		{
			tmp=new Polynomial((h1->coef),h1->exp);
			tmp->link=subtract.link;
			subtract.link=tmp;
			h1=h1->link;
		}
		
		if(h1==NULL&&h2!=NULL)
		{
			tmp=new Polynomial((-1)*(h2->coef),h2->exp);
			tmp->link=subtract.link;
			subtract.link=tmp;
			h2=h2->link;
		}
		else if(h2==NULL&&h1!=NULL)
		{
			tmp=new Polynomial((h1->coef),h1->exp);
			tmp->link=subtract.link;
			subtract.link=tmp;
			h1=h1->link;
		}
		
	}

	subtract.output();
	
	cout<<"Would you like to evaluate it? (y/n)\n";
	do{
        cin>>ans;
        if(ans=='y' || ans=='Y')
        {
            subtract.evalPoly();
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
        }
		cout<<"Would you like to evaluate again? (y/n)\n";
    }while(ans!='n');
	
	return ret;
}

void Polynomial::multPoly(Polynomial& first,Polynomial& other)
{
	Polynomial multiple;
	
	multiple=first*other;
}

Polynomial operator*(Polynomial& first, Polynomial& second)
{
	Polynomial *h1, *h2, *tmp, multiple, ret;
	char ans;
	
	h1=first.link;
	multiple.link=NULL;

	//Simulates FIOL
	while(h1!=NULL)
	{
		h2=second.link;
		while(h2!=NULL)
		{
			tmp=new Polynomial((h1->coef*h2->coef),(h1->exp+h2->exp));
			tmp->link=multiple.link;
			multiple.link=tmp;
			h2=h2->link;
		}
		h1=h1->link;
	}
	
	multiple.output();
	
	cout<<"Would you like to evaluate it? (y/n)\n";
	do{
        cin>>ans;
        if(ans=='y' || ans=='Y')
        {
            multiple.evalPoly();
        }
        else if(ans=='n' || ans=='N')
        {
            break;
        }
        else
        {
            cout<<"Please choose an option\n";
        }
		cout<<"Would you like to evaluate again? (y/n)\n";
    }while(ans!='n');
	
	
	return ret;
}