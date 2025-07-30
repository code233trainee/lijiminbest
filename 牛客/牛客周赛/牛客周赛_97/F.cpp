#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1), ma(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]] = i;
    }
    vector<ll> stk;
    vector<ll> R(n+1, n+1);
    for(int i = n; i >= 1; i--)
    {
        while(stk.size() && a[stk.back()] < a[i])
        {
            stk.pop_back();
        }
        if(stk.size())
        {
            R[i] = stk.back();
        }
        stk.emplace_back(i);
    }

    stk.clear();
    vector<ll> L(n+1);
    for(int i = 1; i <= n; i++)
    {
        while(stk.size() && a[stk.back()] < a[i])
        {
            stk.pop_back();
        }
        if(stk.size())
        {
            L[i] = stk.back();
        }
        stk.emplace_back(i);
    }

    vector<ll> b(m+1);
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        b[i] = ma[b[i]];
    }

    ll ans = 1;
    if(L[b[1]] > 0 || R[b[m]] <= n)
    {
        ans = 0;
    }
    for(int i = 1; i < m; i++)
    {
        ll r = min(R[b[i]], b[i + 1]) - 1;
        ll l = max(b[i], L[b[i+1]]);
        ans *= max(0ll, r - l + 1);
        ans %= MOD; 
    }
    cout << ans << endl;
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