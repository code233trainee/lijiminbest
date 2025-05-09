#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    c -= abs(a - b);
    if(a < b)
    {
        a = b;
    }
    else
    {
        b = a;
    }
    if(c < a)
    {
        cout << "NO\n";
    }
    else
    {
        int temp = c - a;
        if(temp % 3 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}