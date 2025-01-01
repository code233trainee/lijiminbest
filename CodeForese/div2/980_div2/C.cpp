#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    ll a1 = a.first + a.second;
    ll b1 = b.first + b.second;
    
    return a1 < b1;
    
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        cout << a[i].first << " " << a[i].second << " \n"[i == n - 1];
    }
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