#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> cnt(n);
    for(int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        cnt[(x + y) % n]++;
    }
    ll ans = m * (m - 1) / 2;
    for(auto z : cnt)
    {
        ans -= z * (z - 1) / 2;
    }
    cout << ans;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}