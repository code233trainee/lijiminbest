#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(auto &z : a)
    {
        cin >> z;
    }
    for(auto &z : b)
    {
        cin >> z;
    }
    vector<pair<int, int>> ev;
    for(int i = 0; i < n; i++)
    {
        ev.emplace_back(a[i], 1);
        ev.emplace_back(b[i], 2);
    }
    sort(ev.begin(), ev.end());
    ll ans = 0;
    int cnt = n;
    int bad = 0;
    for(int i = 0; i < 2 * n;)
    {
        int x = ev[i].first;
        //无论是a还是b,只要没有超过最坏评论数量，我们就取最大的价格
        if(bad <= k)
        {
            ans = max(ans, x * 1LL * cnt);
        }
        while(i < 2 * n && ev[i].first == x)
        {
            bad += (ev[i].second == 1);
            bad -= (ev[i].second == 2);
            cnt -= (ev[i].second == 2);
            i++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}