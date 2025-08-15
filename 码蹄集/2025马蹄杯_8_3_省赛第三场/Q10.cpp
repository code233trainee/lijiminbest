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
    ll frt = -1;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    frt = lowerNum(a[0]);
    for(ll i = 1; i < n; i++)
    {
        frt = frt * lowerNum(a[i]);
    }
    ll ans = 0;
    while(frt)
    {
        ans = frt % 10;
        frt /= 10;
        if(ans != 0)
        {
            break;
        }
    }
    cout << ans;
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