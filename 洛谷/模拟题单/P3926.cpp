#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a, c, p, q, r, x;
    cin >> a >> c >> p >> q >> r >> x;
    if(c - a > 0)
    {
        int temp = c - a;
        if(temp*p > x)
        {
            int d = x / p;
            cout << a + d << "\n";
            return 0;
        }
        else
        {
            x -= temp*p;
            a = c;
        }
    }
    if(a == c)
    {
        if(x <= q)
        {
            cout << a << "\n";
            return 0;
        }
        else
        {
            x -= q;
        }
    }
    a += x / r;
    cout << a << "\n";
    return 0;
}