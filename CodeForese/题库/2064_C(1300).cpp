// https://codeforces.com/problemset/problem/2064/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), pre(n), suf(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(a[0] > 0)
    {
        pre[0] = a[0];
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i] > 0)
        {
            pre[i] = pre[i-1] + a[i]; 
        }
        else
        {
            pre[i] = pre[i-1];
        }
    }
    if(a[n-1] < 0)
    {
        suf[n-1] = -a[n-1];
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] < 0)
        {
            suf[i] = suf[i+1] - a[i];
        }
        else
        {
            suf[i] = suf[i+1];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, pre[i] + suf[i]);
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