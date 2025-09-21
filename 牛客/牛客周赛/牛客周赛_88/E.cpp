#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
	long long n, k;
	cin >> n >> k;
	vector< vector<long long> > a(n+1, vector<long long>(2));
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i][0];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i][1];
	}
	// vector< vector<long long> > dp(n+1, vector<long long>(2, -1e18));
	// dp[0][0] = 0;
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < 2; j++)
	// 	{
	// 		dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1][j]);
	// 		if(dp[i][j] >= k)
	// 		{
	// 			dp[i+1][j^1] = max(dp[i+1][j^1], dp[i][j]+a[i+1][j^1]-k);
	// 		}
	// 	}
	// }
	vector<vector<long long>> dp(n + 1, vector<ll>(2, -1e18));
	dp[1][0] = a[1][0];
	for(int i = 2; i <= n; i++)
	{
		if(dp[i-1][1] >= k)
		{
			dp[i][0] = max(dp[i-1][0] + a[i][0], dp[i-1][1] + a[i][0] - k);
		}
		else
		{
			dp[i][0] = dp[i-1][0] + a[i][0];
		}
		if(dp[i-1][0] >= k)
		{
			dp[i][1] = max(dp[i-1][1] + a[i][1], dp[i-1][0] + a[i][1] - k);
		}
		else
		{
			dp[i][1] = dp[i-1][1] + a[i][1];
		}
	}
	cout << max(dp[n][0], dp[n][1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
