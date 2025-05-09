#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    vector<bool> vis(n+1, false);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bool ok = true;
    for(int i = 1; i <= n; i++)
    {
        if(a[i].size() != 2)
        {
            ok = false;
            break;
        }
    }
    auto dfs = [&](auto&& self, int node) -> void {
        vis[node] = true;
        for(auto n : a[node])
        {
            if(!vis[n])
            {
                self(self, n);
            }
        }
    };
    if(ok) 
    {
        dfs(dfs, 1); 
        for (int i = 1; i <= n; i++) 
        {
            if (!vis[i]) 
            {
                ok = false;
                break;
            }
        }
    }
    if(ok)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}