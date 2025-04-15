#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> pre(n+1);
    vector<ll> suf(n+2);
    vector<ll> mxsuf(n+2);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(ll i = n; i >= 1; i--)
    {
        suf[i] = suf[i+1] + a[i];
    }
    for(ll i = n; i >= 1; i--)
    {
        mxsuf[i] = max(mxsuf[i+1], suf[i]);
    }
    ll cnt = 0;
    ll j = 0;
    while(k >= j)
    {
        k++;
        k -= j;
        j++;
        cnt++; 
    }
    ll mx = 0;
    // mx = max(mx, pre[min(cnt, n)]);
    // mx = max(mx, suf[max(n-cnt, 1ll)]);
    for(ll i = 1; i <= cnt && i <= n; i++)
    {
        mx = max(mx, pre[i]);
    }
    for(ll i = 1; i <= cnt && i <= n; i++)
    {
        mx = max(mx, suf[n - i + 1]);
    }
    for(ll i = 1; i <= cnt && i <= n; i++)
    {
        mx = max(mx, pre[i] + mxsuf[max(n - (cnt - i) + 1, i+1)]);
    }
    cout << mx;
    return 0;
}