#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll x = 1;
    for(ll i = 0; i < n - 1; i++)
    {
        ll g = gcd(b[i], b[i+1]);
        x = lcm(x, b[i] / g);
    }
    cout << x << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}