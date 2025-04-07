#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b + c)
    {
        cout << 'l';
    }
    else if(b > a + c)
    {
        cout << "q";
    }
    else if(c > a + b)
    {
        cout << "b";
    }
    else
    {
        cout << "-1";
    }
    return 0;
}