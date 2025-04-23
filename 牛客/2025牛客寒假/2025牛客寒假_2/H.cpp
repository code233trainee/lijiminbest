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
        if(abs(a - b) == 1 && abs(c - d) == 1)
        {
            cout << a << " " << d << endl;
            cout << a << " " << c << endl;
            cout << b << " " << c << endl;
        }
        else
        {
            if(b - a < d - c) {
                cout << a << " " << c << endl;
                cout << a << " " << c + 1 << endl;
                cout << a + 1 << " " << d << endl;
            } else {
                cout << a << " " << c << endl;
                cout << a + 1 << " " << c << endl;
                cout << b << " " << c + 1 << endl;
            }
        }
    }
    return 0;
}