#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 5;

int n;
ll min_pre[maxn], sum[maxn], max_pre[maxn], dep[maxn];
int a[maxn];
vector<int> e[maxn];

void dfs(int now, int last)
{
    dep[now] = dep[last] + 1;
    if(dep[now] % 2 == 1)
    {
        sum[now] = sum[last] + a[now];
    }
    else
    {
        sum[now] = sum[last] - a[now];
    }

    max_pre[now] = max(max_pre[last], sum[now]);
    min_pre[now] = min(min_pre[last], sum[now]);
    for(auto nxt : e[now])
    {
        if(nxt == last)
        {
            continue;
        }
        dfs(nxt, now);
    }
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        min_pre[i] = max_pre[i] = sum[i] = dep[i] = 0;
        e[i].clear();
    }

    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(dep[i] % 2 == 1)
        {
            cout << sum[i] - min_pre[i] << " ";
        }
        else
        {
            cout << -(sum[i] - max_pre[i]) << " ";
        }
    }
    cout << endl;
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