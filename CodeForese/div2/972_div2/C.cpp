#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    const string narek = "narek";
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<int> dp(5, -1e8), ndp;
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        ndp = dp;

        for(int j = 0; j < 5; j++)
        {
            if(dp[j] == -1e8) continue;

            int counted_score = 0, next = j;
            
            for(int k = 0; k < m; k++)
            {
                int ind = narek.find(s[i][k]);
                
                if(ind == -1) continue;

                if(next == ind)
                {
                    next = (next + 1) % 5;
                    counted_score++;
                }
                else
                {
                    counted_score--;
                }
            }

            ndp[next] = max(ndp[next], dp[j] + counted_score);
        }
        dp = ndp;
    }
    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        ans = max(ans, dp[i] - 2 * i);
    }
    cout << ans << endl;
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