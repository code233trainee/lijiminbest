#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(abs(a - b) > abs(c - d))
        {
            cout << a << " " << c << endl;
            cout << b << " " << d << endl;
            cout << b - 1 << " " << d << endl;
        }
        else
        {
            cout << b << " " << c << endl;
            cout << a << " " << d << endl;
            cout << a << " " << d - 1 << endl;
        }
    }
    return 0;
}