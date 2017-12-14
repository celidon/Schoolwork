/*
   File Name: booklist.cpp
   Developer: Anthony Hansen
   Date Last Modified: ..2014
   Description: The assignment was to write a program using an STL vector to
				store a list of book titles, authors, and publication dates. The
				user can then add a book to the list, see the list, or quit the
				program. The list is sorted first by author name and then by book
				title.
   Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

struct BookInfo
{
	string title;
	string author;
	int pub_date;
};

bool operator <(const BookInfo& book1, const BookInfo& book2)
{
	if(book1.author!=book2.author)
	{
		return book1.author<book2.author;
	}
	else
	{
		return book1.title<book2.title;
	}
}

int main()
{
	vector<BookInfo> library;
	
	BookInfo newbook;
	int choice;
	
	cout<<"Please enter a book: \nWhat is the book's title?\n";
	getline(cin,newbook.title);
	cout<<"Who is the author of "<<newbook.title<<"?\n";
	getline(cin,newbook.author);
	cout<<"In which year was "<<newbook.title<<" published?\n";
	cin>>newbook.pub_date;
	library.push_back(newbook);
	
	do{
	cout<<"Select from the following choices:\n1) Add a new book\n2) Print listing sorted by author\n3) Quit\n";
	cin>>choice;
	if(choice==1)
	{
		cin.ignore();
		cout<<"What is the book's title?\n";
		getline(cin,newbook.title);
		cout<<"Who is the author of "<<newbook.title<<"?\n";
		getline(cin,newbook.author);
		cout<<"When was "<<newbook.title<<" published?\n";
		cin>>newbook.pub_date;
		library.push_back(newbook);
	}
	else if(choice==2)
	{
		std::sort(library.begin(),library.end());
		for (vector<BookInfo>::iterator it = library.begin(); it!=library.end(); it++)
		{
			cout<<it->author<<"   "<<it->title<<"   "<<it->pub_date<<endl;
		}
	}
	else if(choice==3)
	{
		break;
	}
	else
	{
		cout<<"Please make a valid selection.\n";
	}
	}while(choice!=3);
	
	cout<<"Have a good read!\n";
	
	return 0;
}