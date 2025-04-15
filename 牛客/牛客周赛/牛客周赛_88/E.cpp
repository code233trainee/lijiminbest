#include <bits/stdc++.h>
#include <queue>
using namespace std;
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
	vector< vector<long long> > dp(n+1, vector<long long>(2, -1e18));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+1][j]);
			if(dp[i][j] >= k)
			{
				dp[i+1][j^1] = max(dp[i+1][j^1], dp[i][j]+a[i+1][j^1]-k);
			}
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
