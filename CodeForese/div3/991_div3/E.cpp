#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    int m = b.size();
    //编译器会自动的推导类型，dp的类型是vector<vector<int>>
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i < n)
            {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (a[i] != c[i+j]));
            }
            if(j < m)
            {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + (b[j] != c[i+j]));
            }
        }
    }
    cout << dp[n][m] << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}