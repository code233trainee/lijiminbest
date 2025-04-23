#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<vector<int>> idx(n);
    vector<int> cnt(m);
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        cnt[i] = k;
        a[i].resize(k);
        for(auto &z : a[i])
        {
            cin >> z;
            z--;
            idx[z].push_back(i);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        b--;
        for(auto id : idx[b])
        {
            cnt[id]--;
            if(cnt[id] == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}