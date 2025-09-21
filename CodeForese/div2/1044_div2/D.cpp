//https://codeforces.com/contest/2133/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> dp(n+1, 1e18+10);
    dp[0] = 0;
    //dp数组的意义:
    //处理到第i个元素怪物所需要的最小次数
    dp[1] = a[1];
    for(int i = 2; i <= n; i++)
    {
        //直接处理前面所有的怪物
        ll A = dp[i-1] + a[i] - 1;//最后肯定会摔一下
        //处理前一个，让它摔一下+剩余血量(如果有)
        ll B = dp[i-2] + a[i-1] + max(0ll, a[i] - (i-1));
        //取这两种方案的最小值
        dp[i] = min(A, B);
    }
    cout << dp[n] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}