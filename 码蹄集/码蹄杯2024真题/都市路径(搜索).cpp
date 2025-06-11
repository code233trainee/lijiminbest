#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
vector<int> adj[N];
vector<bool> vis(N);
vector<int> dis(N, -1);
void bfs()
{
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int u, m;
        cin >> u >> m;
        for(int j = 0; j < m; j++)
        {
            int v;
            cin >> v;
            adj[u].push_back(v);
        }
    }
    dis[1] = 0;
    bfs();
    for(int i = 1; i <= n; i++)
    {
        cout << i << " " << dis[i] << endl;
    }
    return 0;
}