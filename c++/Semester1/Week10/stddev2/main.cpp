
#include <iostream>
#include <fstream>

using namespace std;

void fillArray(double [], int);


int main()
{
    int size;
    double a[size], b[size], ave;

    fillArray(a, size);

    cout << a[3];

    return 0;
}

void fillArray(double arr[], int size)
{
    int i = 0;
    ifstream infile;
    double next;

    infile.open("stddev.dat");

    while(infile >> next)
    {
        arr[i] = next;
        i++;
    }
    size = i + 1;
}
