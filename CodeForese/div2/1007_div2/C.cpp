#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<int>> adj(n+1, vector<int>());
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 与老鼠的初始位置无关
    // 我们可以直接从每一层的节点开始遍历
    // 老鼠的位置最坏不会超过这个最深的距离
    // 直到到达我们的根节点，也就是我们的陷阱位置
    vector<vector<int>> dis(n+1, vector<int>());
    vector<int> d(n+1);
    auto dfs = [&](auto &&self, int v, int par) -> void {
        d[v] = d[par]+1;
        dis[d[v]].push_back(v);
        for(int u : adj[v])
        {
            if(u == par) continue;
            self(self, u, v);
        }
    };
    dfs(dfs, e, 0);
    for(int i = n; i >= 1; i--)
    {
        for(int j : dis[i])
        {
            cout << j << " ";
        }
    }
    cout << "\n";
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