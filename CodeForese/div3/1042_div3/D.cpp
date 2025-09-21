#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>());
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(n == 2)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i].size() == 1)
        {
            ans++;
        }
    }
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(auto z : a[i])
        {
            if(a[z].size() == 1)
            {
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }
    cout << ans - mx << endl;
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