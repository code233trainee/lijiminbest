#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> s(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        //利用前缀和可以很快求出区间和
    }
    
    for(ll k = 1; k <= n - 2; k++)
    {
        vector<ll> pre(n+1);
        vector<ll> suf(n+2);
        for(ll i = 1; i <= n; i++)
        {
            pre[i] = max(pre[i - 1], s[i] - s[max(0ll, i - k)]);
        }
        for(ll i = n; i >= 1; i--)
        {
            suf[i] = max(suf[i + 1], s[min(n, i + k - 1)] - s[i - 1]);
        }

        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, max(pre[i-1], suf[i+1]) - a[i]);
        }
        cout << ans << " ";
    }
    cout << max(s[n] - a[1] - a[1], s[n-1] - a[n]) << " 0\n";
}
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}