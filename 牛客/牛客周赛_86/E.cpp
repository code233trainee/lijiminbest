#include <bits/stdc++.h>
using namespace std;
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //多边形的其中一条边必须小于其他边之和
    //所以本题变成了用动态规划求最小的多边形周长
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<int> dp(n * a[n] + 1);
    dp[0] = 1;
    
    int ans = 1e9;
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i]+1; j < n * a[n]; j++)
        {
            if(dp[j])
            {
                ans = min(ans, a[i] + j);
                break;
            }
        }
        //总和在最坏情况下也不会很大(1e4),所以我们可以暴力dp
        for(int j = n * a[n]; j >= a[i]; j--)
        {
            //反向遍历，防止重复使用边长
            //dp[j - a[i]]可以到达，那么加上这个也可以到达(dp[j])
            dp[j] |= dp[j - a[i]];
        }
    }
    if(ans > 1e8)
    {
        ans = -1;
    }
    cout << ans << "\n";
}
int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}