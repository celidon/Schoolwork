/*
   File Name: stacktemplate.cpp
   Developer: Anthony Hansen
   Date Last Modified: 10.04.2014
   Description: The assignment was to write a program that uses a template in
				order to implement a stack data structure.
Email Address: hansen.tony92@gmail.com
*/

#include<iostream>

using namespace std;

template<class baseType>
struct StackFrame
{
	baseType data;
	StackFrame *link;
};

template<class baseType>
class Stack
{
	public:
	  Stack();
	  Stack(const Stack&);
	  ~Stack();
      void push(baseType);
	  baseType pop();
	  bool empty();
   private:
	  typedef StackFrame<baseType>* StackFramePtr;
	  StackFramePtr top;

};

template<class baseType>
Stack<baseType>::Stack()
{
  top = NULL;
}

template<class baseType>
Stack<baseType>::Stack(const Stack& s)
{
	StackFramePtr current = s.top;
	StackFramePtr temp = new StackFrame<baseType>; 
	temp->data = s.top->data;
	top = temp;
   while	(temp != NULL)
		temp = temp->link;
   while(temp != s.top)
	{
		push(temp->link->data);
	}
}

template<class baseType>
Stack<baseType>::~Stack()
{
	char next;
	while(!empty())
	{
     next = pop();
	}
}

template<class baseType>
baseType Stack<baseType>::pop()
{
	baseType c;
	StackFramePtr temp;
	if(!empty())
	{
     c = top->data;
	  temp = top;
	  top = top->link;
	  delete temp;
	}
	return c;
}

template<class baseType>
bool Stack<baseType>::empty()
{
	return top == NULL;
}

template<class baseType>
void Stack<baseType>::push(baseType c)
{
	StackFramePtr temp = new StackFrame<baseType>;
	temp->data = c;
	temp->link = top;
	top = temp;
}

int main()
{
   
   Stack<char> s;
	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');

   Stack<int> s2;
    s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	
	cout<<"Character Stack:\n";
	while(!s.empty())
		cout << s.pop() << endl;
		
	cout<<"\nInteger Stack:\n";
	while(!s2.empty())
		cout << s2.pop() << endl;
	return 0;
}