#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll x;
    cin >> x;
    if(x%33)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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