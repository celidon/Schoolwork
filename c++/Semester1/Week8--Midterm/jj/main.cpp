#include <iostream>

using namespace std;

int main()
{
    int loopCount = 20;
    int beta = 10;
    while (loopCount < 51)
    {
        beta = beta + 5;
        loopCount++;
    }
    cout << loopCount;
    return 0;
}
