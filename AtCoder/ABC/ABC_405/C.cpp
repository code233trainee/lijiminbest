#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pre(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i+1] = pre[i] + a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += a[i]*(pre[n] - pre[i+1]);
    }
    cout << ans << "\n";
    return 0;
}