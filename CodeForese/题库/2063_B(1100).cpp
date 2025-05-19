#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, l, r;
    cin >> n >> l >> r;
    l--;
    r--;
    vector<ll> a(n), b, c;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0; i <= r; i++)
    {
        b.push_back(a[i]);
    }
    for(ll i = l; i < n; i++) 
    {
        c.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = INT64_MAX;
    ll cnt = r - l + 1;
    ll total = 0;
    for(ll i = 0; i < b.size(); i++)
    {
        if(cnt--)
        {
            total += b[i];

        }
        else
        {
            break;
        }
    }
    ans = min(ans, total);
    total = 0;
    cnt = r - l + 1;
    for(ll i = 0; i < c.size(); i++)
    {
        if(cnt--)
        {
            total += c[i];
        }
        else
        {
            break;
        }
    }
    ans = min(ans, total);
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}