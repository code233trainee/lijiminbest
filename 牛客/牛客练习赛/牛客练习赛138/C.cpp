#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1, -1);
    dist[k] = 0;
    queue<int> q;
    q.push(k);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto &z : adj[u])
        {
            if(dist[z] == -1)
            {
                dist[z] = dist[u] + 1;
                q.push(z);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i != k && adj[i].size() == 1)
        {
            ans = max(ans, dist[i]);
        }
    }
    cout << ans + 1 << endl;
    return 0;
}