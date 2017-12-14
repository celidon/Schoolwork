#include <iostream>

using namespace std;

int main()
{
    int fnum=2;
    int snum=5;
    int code;

    cin>>code;

    switch(code)
    {
    case 1:
        cout<<"The sum is "<<fnum+snum<<endl;
        break;

    case 2:
        cout<<"The product is "<<fnum*snum<<endl;
        break;

    default:
        cout<<"The difference is "<<fnum-snum<<endl;
    }

    return 0;
}
