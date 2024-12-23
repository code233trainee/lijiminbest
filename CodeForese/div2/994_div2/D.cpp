#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[510][510], a[510][510];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //1e18差不多是long long类型的最大值了
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int shift = 0; shift < m; shift++)
        {
            vector<ll> tmp(m, 1e18);
            for(int j = 0; j < m; j++)
            {
                tmp[j] = dp[i-1][j] + a[i][(j + shift)%m] + k*1ll*shift;
            }
            for(int j = 0; j < m; j++)
            {
                tmp[j] = min(tmp[j], tmp[(j+m-1)%m] + a[i][(j+shift)%m]);
            }
            for(int j = 0; j < m; j++)
            {
                tmp[j] = min(tmp[j], tmp[(j+m-1)%m] + a[i][(j+shift)%m]);
            }
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = min(dp[i][j], tmp[j]);
            }
        }
    }
    cout << dp[n][m-1] << "\n";
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