#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(n&1)
    {
        if(a*2 >= b)
        {
            cout << (n/2)*b + a << "\n";
        }
        else
        {
            cout << n*a << "\n";
        }
    }
    else
    {
        if(a*2 >= b)
        {
            cout << (n/2)*b << "\n";
        }
        else
        {
            cout << n*a << "\n";
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