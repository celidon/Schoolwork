/*
File Name: merge_organise.cpp
Developer: Anthony Hansen
Date Last Modified: 10.10.2013
Description: The assignment was to write a program that opens two data files
             of intergers and merges the lists, organising the data from
             smallest ro largest interger.
Email Address: hansen.tony92@gmail.com
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    int next1, next2;
    ifstream in_stream1, in_stream2;
    ofstream out_stream;

    in_stream1.open("file1.dat");
    if (in_stream1.fail())
    {
        cout<<"Input 'file1.dat' opening failed.\n";
        exit(1);
    }

    in_stream2.open("file2.dat");
    if (in_stream2.fail())
    {
        cout<<"Input 'file2.dat' opening failed.\n";
        exit(1);
    }

    out_stream.open("file3.dat");
    if (out_stream.fail())
    {
        cout<<"Output file opening failed.\n";
        exit(1);
    }

    in_stream2 >> next2;

    while (in_stream1 >> next1)
    {
        if (next1 < next2)
        {
            out_stream << next1 << endl;
        }
        else if (next1 == next2)
        {
            out_stream << next1 << endl << next2 << endl;
            in_stream2 >> next2;
        }
    }

    out_stream << next2 << endl;

    while (in_stream2 >> next2)
    {
        out_stream << next2 << endl;
    }

    in_stream1.close();
    in_stream2.close();
    out_stream.close();

    return 0;
}
