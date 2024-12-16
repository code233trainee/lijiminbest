#include <bits/stdc++.h>
using namespace std;
bool dp[361];
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i]; j <= 3600; j++)
        {
            //转化为了完全背包问题
            dp[j%360] = max(dp[j%360], dp[(j-a[i])%360]);
            dp[j%360] = max(dp[j%360], dp[(j+a[i])%360]);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int q;
        cin >> q;
        if(dp[q] == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}