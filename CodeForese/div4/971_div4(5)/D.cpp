#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n = 0;
    cin >> n;
    ll ans = 0;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> a(n+1);
    map<pair<ll, ll>, bool> m;
    for(ll i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        a[x[i]]++;
        m[{x[i], y[i]}] = true;
    }
    for(ll i = 0; i <= n; i++)
    {
        if(a[i] == 2)
        {
            ans += n - 2;
        }
    }
    for(ll i = 0; i <= n; i++)
    {
        if((m[{i, 0}] && m[{i+1, 1}]) && m[{i+2, 0}])
        {
            ans++;
        }
        if((m[{i,1}] && m[{i+1, 0}]) && m[{i+2, 1}])
        {
            ans++;
        }
    }
    cout << ans << endl;

}

int main()
{
    ll t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
}