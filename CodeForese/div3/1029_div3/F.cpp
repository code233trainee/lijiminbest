#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10, MOD = 1e9 + 7;

vector<ll> adj[N], lens;
ll pw[N];
ll lca;

void dfs(ll u, ll par, ll len)
{
    if(adj[u].size() > 2)
    {
        lca = len;
    }

    bool leaf = true;
    for(ll v : adj[u])
    {
        if(v != par)
        {
            dfs(v, u, len+1);
            leaf = false;
        }
    }

    if(leaf)
    {
        lens.push_back(len);
    }
}
void solve()
{
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    lens.clear();
    lca = -1;

    for(int i = 0; i < n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    adj[1].push_back(0);
    dfs(1, 0, 1);
    if(lens.size() > 2)
    {
        cout << 0 << endl;
    }
    else if(lens.size() == 1)
    {
        cout << pw[n] << endl;
    }
    else
    {
        ll diff = abs(lens[0] - lens[1]);
        ll x = diff + lca;
        if(diff)
        {
            cout << (pw[x] + pw[x-1]) % MOD << endl;
        }
        else
        {
            cout << (2 * pw[x]) % MOD << endl;
        }
    }
}
int main()
{
    pw[0] = 1;
    for(int i = 1; i < N; i++)
    {
        pw[i] = (pw[i-1] * 2) % MOD;
    }

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}