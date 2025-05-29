#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    double c = a / b;
    int d = a / b;
    if((double)(c - d) > (double)(d + 1 - c))
    {
        cout << d + 1;
    }
    else
    {
        cout << d;
    }
    return 0;
}