#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if (a > b && a <= c || b != d && b == c)
        m = b;
    else if (b > c || d < a )
             m = a;
   else
        m = d;

cout << m << endl;

    return 0;
}
