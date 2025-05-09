#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> vp(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> vp[i].first;
    }
    for(ll i = 0; i < n; i++)
    {
        cin >> vp[i].second;
    }
    vector<ll> a;
    for(ll i = 0; i < n; i++)
    {
        if(vp[i].first > vp[i].second)
        {
            ans += vp[i].first;
            a.push_back(vp[i].second);
        }
        else
        {
            ans += vp[i].second;
            a.push_back(vp[i].first);
        }
    }
    sort(a.begin(), a.end());
    for(ll i = a.size() - 1; i >= 0; i--)
    {
        if(k == 1)
        {
            ans += 1;
            break;
        }
        else
        {
            k--;
            ans += a[i];
        }
    }
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}