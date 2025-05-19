#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int mans = 0;
    vector<int> sdeg = deg;
    sort(sdeg.begin(), sdeg.end());

    for(int i = 0; i < n; i++)
    {
        int ans = deg[i];
        vector<int> ideg;

        for(int v : adj[i])
        {
            ideg.push_back(deg[v]);
        }
        ideg.push_back(deg[i]);
        sort(ideg.rbegin(), ideg.rend()); //降序排列

        vector<int> rem;
        int mx = -1;

        for(int d: ideg)
        {
            if(sdeg.back() == d)
            {
                sdeg.pop_back();
                rem.push_back(d);
            }
        }

        if(!sdeg.empty())
        {
            mx = max(mx, sdeg.back());
        }

        for(int v : adj[i])
        {
            mx = max(mx, deg[v] - 1);
        }

        for(int d : rem)
        {
            sdeg.push_back(d);
        }

        sort(sdeg.begin(), sdeg.end());

        mans = max(ans + mx - 1, mans);
    }
    cout << mans << endl;
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
