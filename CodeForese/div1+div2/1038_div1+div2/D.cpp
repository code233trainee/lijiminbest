#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    const int inf = 1e9;
    vector<int> f(n, inf);
    f[0] = 0;
    for(int t = 0;; t++)
    {
        vector<int> nf(n, inf);
        for(int i = 0; i < n; i++)
        {
            if(f[i] >= inf) continue;
            nf[i] = min(nf[i], f[i] + 1);
            nf[d[i][t % d[i].size()]] = min(nf[d[i][t % d[i].size()]], f[i]);
        }
        f = nf;
        if(f[n-1] < inf)
        {
            cout << t + 1 << " " << f[n-1] << endl;
            return;
        }
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