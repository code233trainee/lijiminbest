#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    vector<ll> pre(n+1);
    vector<ll> suf(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    } 
    for(int i = n; i >= 1; i--)
    {
        suf[i] = suf[i+1] + b[i];
    }
    ll ans = INT64_MAX;
    for(int i = 1; i < n; i++)
    {
        ans = min(ans, pre[i] + suf[i+1]);
    }
    for(int i = 1; i < n; i++)
    {
        ans = min(ans, (pre[n] - pre[i]) + (suf[1] - suf[i+1]));
    }
    ans = min( ans, min(pre[n], suf[1]));
    cout << ans << endl;
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