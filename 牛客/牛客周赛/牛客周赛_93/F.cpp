#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n + 1, vector<ll>(n+1, 3));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n + 3, vector<ll>(n + 3)));
    if(n % 2 == 0)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[n/2][j] == a[n / 2 + 1][j])
            {
                dp[0][j][j]++;
            }
            if(a[n / 2][j] == a[n / 2 + 1][j + 1])
            {
                dp[0][j][j + 1]++;
            }
        }

        ll m1 = n / 2;
        ll m2 = n / 2 + 1;
        for(int d = 1; d <= n / 2 - 1; d++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                {
                    dp[d & 1][j][k] = 0;
                }
            }
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                {
                    if(a[m1 - d][j] == a[m2 + d][k])
                    {
                        dp[d&1][j][k] += dp[(d - 1) & 1][j][k];
                        dp[d&1][j][k] += dp[(d - 1) & 1][j+1][k];
                        dp[d&1][j][k] += dp[(d - 1) & 1][j][k-1];
                        dp[d&1][j][k] += dp[(d - 1) & 1][j+1][k-1];
                        dp[d&1][j][k] %= mod;
                    }
                }
            }
        }
        for(int j = 1; j <= n; j++)
        {
            ans += dp[(n / 2 - 1) & 1][1][j];
            ans %= mod;
        }
    }
    else
    {
        int m = n / 2 + 1;
        for(int j = 1; j <= m; j++)
        {
            dp[0][j][j]++;
        }

        for(int d = 1; d <= n/2; d++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                {
                    dp[d & 1][j][k] = 0;
                }
            }
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                {
                    if(a[m - d][j] == a[m + d][k])
                    {
                        dp[d&1][j][k] += dp[(d - 1) & 1][j][k];
                        dp[d&1][j][k] += dp[(d - 1) & 1][j+1][k];
                        dp[d&1][j][k] += dp[(d - 1) & 1][j][k-1];
                        dp[d&1][j][k] += dp[(d - 1) & 1][j+1][k-1];
                        dp[d&1][j][k] %= mod;
                    }
                }
            }
        }

        for(int j = 1; j <= n; j++)
        {
            ans += dp[(n / 2) & 1][1][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}