#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> pre(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = 1+10; i <= n; i++)
    {
        pre[i] -= pre[i-10];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, pre[i]);
    }
    cout << ans;
    return 0;
}