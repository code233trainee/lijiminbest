// https://codeforces.com/problemset/problem/2022/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    ll mx = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    ll res = (sum + k - 1) / k;
    cout << max(res, mx) << endl;
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