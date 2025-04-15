#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll pre[1000010];
ll suf[1000010];
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll pace0 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] < 0)
        {
            pre[(-1*a[i])]++;
        }
        else if(a[i] > 0)
        {
            suf[a[i]]++;
        }
        else
        {
            pace0++;
        }
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= m; i++)
    {
        pre[i] = pre[i-1] + pre[i];
        suf[i] = suf[i-1] + suf[i];
    }
    ll mx = -1;
    mx = max(pre[min(m, (ll)(1e6))], suf[min(m, (ll)(1e6))]);
    for(ll i = 1; i <= m && 2*i <= m; i++)
    {
        mx = max(mx, pre[i] + suf[m - 2*i]);
        mx = max(mx, suf[i] + pre[m - 2*i]);
    }
    cout << mx + pace0 << endl;
    return 0;
}