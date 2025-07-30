#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 30; i >= 0; i--)
    {
        ll v = (1ll << i);
        ll cost = m * v;
        if(n >= cost)
        {
            n -= cost;
            ans |= (1ll << i);
        }
        else
        {
            cost -= m;
            if(n <= cost) continue;
            // n - k*v <= cost
            // k*v >= n - cost
            ll k = (n - cost + v - 1) / v;
            n -= k * v;
        }
    }
    cout << ans << endl;
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