#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll sum = 0;
        for(int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            ans += 1ll * x * (m - j);//消除同组之间差距
            sum += x;
        }
        a[i] = sum;
    }
    //从小到大排序
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        ans += a[i] * i * m;//最小的组已经算过一次了，每次往上一组就会多算一次
    }
    cout << ans << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}