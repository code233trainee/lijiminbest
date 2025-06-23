#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> f(n+1, vector<int>(m+1));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            f[i+1][j+1] = (a[i][j] == 'g' ? 1 : 0);
            f[i+1][j+1] += f[i+1][j] + f[i][j+1] - f[i][j];
        }
    }
    int res = n * m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '.')
            {
                int x1 = max(0, i - k + 1), x2 = min(n - 1, i + k - 1);
                int y1 = max(0, j - k + 1), y2 = min(m - 1, j + k - 1);
                res = min(res, f[x2 + 1][y2 + 1] - f[x1][y2 + 1] - f[x2 + 1][y1] + f[x1][y1]);
            }
        }
    }
    cout << f[n][m] - res << endl;
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