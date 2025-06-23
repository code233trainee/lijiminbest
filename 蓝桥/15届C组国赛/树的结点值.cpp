#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+10;
int n;
vector<int> adj[N];
int dp[N][2];
void dfs(int u, int fa)
{
    dp[u][u&1] += 1;
    for(auto &v : adj[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        dp[u][0]+=dp[v][0];
        dp[u][1]+=dp[v][1];
    }

}
int main()
{
    cin >> n;
    adj[1].push_back(0);
    for(int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    {
        cout << dp[i][i&1] << endl;
    }
    return 0;
}