#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    s = '0' + s + '1';
    vector<ll> c(n + 2);
    for(ll i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    vector<ll> sum(n+3);
    for(ll i = n + 1; i >= 1; i--)
    {
        sum[i] = sum[i+1];
        if(s[i] != s[i-1])
        {
            sum[i] += c[i];
        }
    }

    ll ans = 1e18;
    ll pre = 0;
    ll pre_cost = 0;
    for(int i = 1; i <= n + 1; i++)
    {
        ll u = (s[i] - '0') ^ pre;
        ll now = sum[i + 1];
        if(u == 0)
        {
            now += c[i];
        }
        ans = min(ans ,now + pre_cost);

        if(s[i] != s[i-1])
        {
            pre ^= 1;
            pre_cost += c[i];
        }
    }

    cout << ans << endl;
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