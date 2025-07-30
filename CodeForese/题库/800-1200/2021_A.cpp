#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &z : a)
    {
        cin >> z;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        a[i+1] = (a[i] + a[i+1]) / 2;
        ans = a[i+1];
    }
    cout << ans << "\n";
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