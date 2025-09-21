#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll lowerNum(ll n)
{
    ll res = 0;
    while(n)
    {
        res = n % 100000;
        if(res % 10 == 0)
        {
            n /= 10;
        }
        else
        {
            break;
        }
    }
    return res;
}
void solve()
{
    
}
int main()
{
    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}