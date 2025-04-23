#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> deg(n+1);
    for(int i = 1, u, v; i <= n - 1; i++)
    {
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    ll sum = 0, mn = 1e18;
    ll cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] <= 1)
        {
            sum += a[i];
            cnt++;
        }
        mn = min(mn, a[i]);
    }
    if(cnt % 2 == 1)
    {
        sum += mn;
    }
    cout << sum << endl;
    return 0;
}