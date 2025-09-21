#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+10;
int n, m, x;
vector<bool> vis(N);
set<int> xx;
vector<int> e[N];
vector<int> ans;
void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    ans.push_back(1);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto u : e[v])
        {
            if(!vis[u] && !xx.count(u))
            {
                q.push(u);
                vis[u] = true;
                ans.push_back(u);
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> x;
    for(int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        xx.insert(y);
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs();
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}