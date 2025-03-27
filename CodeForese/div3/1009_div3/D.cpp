#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 10;
int n, m;
ll ans, x[N], r[N];
map<ll, ll> h;
void solve()
{
    cin >> n >> m;
    h.clear();
    ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i];
        for(ll p = x[i] - r[i]; p <= x[i] + r[i]; p++)
        {
            //取y的最大值，整型是向下取整，保证了y的最高点是在圆内的
            h[p] = max(h[p], (ll)(sqrt(r[i] * r[i] - (p - x[i]) * (p - x[i]))));
        }
    }
    for(auto hg : h)
    {
        ans += hg.second * 2 + 1;
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}