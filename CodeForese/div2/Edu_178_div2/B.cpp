#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> mx(n+1);
    vector<ll> suf(n+2);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx[i] = max(mx[i-1], a[i]);
    }
    for(ll i = n; i >= 1; i--)
    {
        suf[i] = a[i] + suf[i+1];
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++)
    {
        ans = suf[n - i + 2] + mx[n - i + 1];
        cout << ans << " \n"[i == n];
    }
}
int main()
{
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}