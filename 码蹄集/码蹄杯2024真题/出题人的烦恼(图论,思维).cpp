#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
vector<int> adj[N];
vector<int> deg(N);
int n, m;

void change(int u)
{
    deg[u]--;
    for(auto v : adj[u])
    {
        if(v == u)
        {
            continue;
        }
        deg[v]--;
        if(deg[v] == 1)
        {
            change(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
        {
            change(i);
        }
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 2)
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}