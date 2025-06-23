#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
ll n, a[N], dp[N][2];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[n + 1][0] = dp[n + 1][1] = 0;
    for(int i = n; i >= 1; i--)
    {
        ll n1, n2, n3;
        //第i位为奇数
        n1 = dp[i + 1][0];//第i位不删
        n2 = dp[i + 1][1];//先删第i位，i+1到n后处理
        n3 = dp[i + 1][0];//先删后面的，再删第i位
        dp[i][1] = max(n1, max(n2, n3));

        //第i位为偶数
        n1 = dp[i + 1][1];//第i位不删
        n2 = dp[i + 1][0] + a[i];//先删第i位，i+1到n后处理
        n3 = dp[i + 1][1] + a[i];//先处理后面的，再删第i位
        dp[i][0] = max(n1, max(n2, n3));
    }
    cout << dp[1][1] << endl;
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