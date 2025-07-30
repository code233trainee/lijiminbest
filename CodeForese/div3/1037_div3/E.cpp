#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n), s(n);
    for(ll i = 0; i < n; i++) cin >> p[i];
    for(ll i = 0; i < n; i++) cin >> s[i];
    auto check = [&]() -> bool {
        vector<ll> a(n);
        for(ll i = 0; i < n; i++)
        {
            //lcm
            a[i] = ll(p[i] * s[i] / gcd(p[i], s[i]));
        }
        ll x = a[0];
        for(ll i = 0; i < n; i++)
        {
            x = gcd(x, a[i]);
            if(x != p[i]) return false;
        }
        x = a[n-1];
        for(ll i = n - 1; i >= 0; i--)
        {
            x = gcd(x, a[i]);
            if(x != s[i]) return false;
        }
        return true;
    };
    cout << (check() ? "YES" : "NO") << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}