#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    int mx = 0;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == mx)
            {
                vp.push_back({i, j});
            }
        }
    }
    int x = -1;
    int y = -1;
    bool okx = true;
    bool oky = true;
    for(auto &z : vp)
    {
        if(z.first != vp[0].first)
        {
            if(y == -1)
            {
                y = z.second;
            }
            else if(z.second != y)
            {
                oky = false;
            }
        }
        if(z.second != vp[0].second)
        {
            if(x == -1)
            {
                x = z.first;
            }
            else if(z.first != x)
            {
                okx = false;
            }
        }
    }
    mx -= (okx || oky);
    cout << mx << endl;
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