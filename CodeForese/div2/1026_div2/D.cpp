#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<array<int, 2>, int> c;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        if(c.count({x, y}))
        {
            c[{x, y}] = min(c[{x, y}], w);
        }
        else
        {
            c[{x, y}] = w;
        }
    }
    vector<vector<array<int, 2>>> d(n);
    for(auto &[x, y] : c)
    {
        d[x[0]].push_back({x[1], y});
    }
    auto check = [&](ll mid) -> bool {
        vector<ll> f(n, -1);
        f[0] = min(mid, ll(a[0]));
        for(int i = 0; i < n; i++)
        {
            for(auto &t : d[i])
            {
                if(t[1] <= f[i])
                {
                    f[t[0]] = max(f[t[0]], min(mid, f[i] + a[t[0]]));
                }
            }
        }
        return f[n - 1] != -1;
    };
    // ll l = 0, r = 1e18;
    // if(!check(r))
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // while(l + 1 < r)
    // {
    //     ll mid = l + (r - l) / 2;
    //     if(check(mid))
    //     {
    //         r = mid;
    //     }
    //     else
    //     {
    //         l = mid;
    //     }
    // }
    // cout << r << endl;
    ll l = 0, r = 1e18;
    if (!check(r)) {
        cout << -1 << endl;
        return;
    }
    while (l < r) {
        ll mid = l + (r - l) / 2;//防止溢出
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;// 或 r，此时 l == r
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