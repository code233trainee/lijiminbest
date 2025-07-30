#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, qn;
    cin >> n >> qn;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<array<int, 3>> edges(n-1);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--;
        edges[i][1]--;
    }
    // c[i][j]: total value of color-j of child of vertex i.
    vector<map<int, ll>> c(n);
    vector<ll> sc(n, 0);
    vector<vector<array<int, 2>>> d(n);
    vector<int> f(n, -1);
    vector<int> ef(n, 0);
    for(auto &t : edges)
    {
        d[t[0]].push_back({t[1], t[2]});
        d[t[1]].push_back({t[0], t[2]});                    
    }
    ll res = 0;
    auto dfs = [&](auto &&self, int x, int fa) -> void {
        f[x] = fa;
        for(auto &t : d[x]) {
            if(t[0] == fa) continue;
            sc[x] += t[1];
            c[x][a[t[0]]] += t[1];
            if(a[x] != a[t[0]]) res += t[1];
            ef[t[0]] = t[1];
            self(self, t[0], x);  // 注意这里要传递 self
        }
    };
    dfs(dfs, 0, -1);  // 调用时也要传递 lambda 自身
    while(qn--)
    {
        int v, x;
        cin >> v >> x;
        v--;
        if(x != a[v])
        {
            // delete a[v].
            if(f[v] != -1 && a[f[v]] != a[v])
            {
                res -= ef[v];
            }
            res -= sc[v] - (c[v].count(a[v]) ? c[v][a[v]] : 0);
            // change.
            if(f[v] != -1)
            {
                c[f[v]][a[v]] -= ef[v];
                if(c[f[v]][a[v]] == 0)
                {
                    c[f[v]].erase(a[v]);
                }
            }
            a[v] = x;
            if(f[v] != -1)
            { 
                c[f[v]][a[v]] += ef[v];
            }
            // add back.
            if(f[v] != -1 && a[f[v]] != a[v])
            {
                res += ef[v];
            }
            res += sc[v] - (c[v].count(a[v]) ? c[v][a[v]] : 0);
        }
        cout << res << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}