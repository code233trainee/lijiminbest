#include <bits/stdc++.h>
using namespace std;
int dfs(int u, int p, vector<int> &V, vector<vector<int>> &a)
{
    int c = V[u];
    for(auto v : a[u])
    {
        if(v == p)
        {
            continue;
        }
        int nc = dfs(v, u, V, a);
        if(nc > 0 && c > 0)
        {
            cout << u + 1 << " " << v + 1 << "\n";
        }
        c += nc;
        
    }
    return c;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> V(n);
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        V[x - 1] = 1;
    }
    cout << m-1 << "\n";
    dfs(0, -1, V, a);
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}