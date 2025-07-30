#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, p;
    cin >> x >> p;
    int q = p / x;
    if(p % x == 0)
    {
        cout << 1 + (q-1) * 2 << endl;
    }
    else
    {
        cout << 2 + (p - (q-1) - 2) * 2 << endl;
    }
}   
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}