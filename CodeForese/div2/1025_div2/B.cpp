#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<pair<int, int>> vp;
    vp.push_back({a, m});
    vp.push_back({n - a + 1, m});
    vp.push_back({n, b});
    vp.push_back({n, m - b + 1});
    int ans = INT_MAX;
    // ceil(log2(x)) 以二为底x的对数，向上取整
    for(auto [f, s] : vp)
    {
        int cnt = 0;
        while(f > 1)
        {
            f = (f + 1) / 2;
            cnt++;
        }
        while(s > 1)
        {
            s = (s + 1) / 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans + 1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

