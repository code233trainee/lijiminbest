#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    if(x == a && x == c)
    {
        cout << b + d << "\n";
        return 0;
    }
    if(x >= a && x >= c)
    {
        cout << b + d << "\n";
        return 0;
    }
    if(x >= a && x <= c)
    {
        cout << b << "\n";
        return 0;
    }
    if(x <= a && x >= c)
    {
        cout << d << "\n";
        return 0;
    }
    if(x <= a && x <= c)
    {
        cout << "0\n";
        return 0;
    }

    return 0;
}