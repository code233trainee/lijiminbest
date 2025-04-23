#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+10;
ll a[N], b[N], p[N];
bool cmp(ll i, ll j)
{
    return a[i] > a[j];
}
bool cmp2(ll a, ll b)
{
    return a > b;
}
void solve()
{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] *= i;
        p[i] = i;
    }
    for(ll i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(p+1, p+1+n, cmp);
    sort(b+1, b+1+n, cmp2);
    vector<ll> ans(n+1);
    for(ll i = 1; i <= n; i++)
    {
        ans[p[i]] = b[i];
    }
    for(ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
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