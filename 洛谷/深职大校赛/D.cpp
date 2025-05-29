#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> pre(m+1);
    vector<ll> a(m+1);
    for(ll i = 1; i <= m; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    ll sum = 0;
    while(n--)
    {
        ll l, r;
        cin >> l >> r;
        sum += pre[r] - pre[l-1];
    }
    cout << sum << endl;
    return 0;
}