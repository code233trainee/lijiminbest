#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1);
    vector<bool> vis(n+1, false);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> nums;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
        {
            nums.push_back(i);
        }
    }
    for(auto u : nums)
    {
        for(auto v : adj[u])
        {
            deg[v]--;
            deg[u]--;
        }
    }
    int cnt1 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
        {
            cnt1++;
        }
        else if(deg[i] > 2)
        {
            cout << "NO\n";
        }
    }
    if(cnt1 == 0 || cnt1 == 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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