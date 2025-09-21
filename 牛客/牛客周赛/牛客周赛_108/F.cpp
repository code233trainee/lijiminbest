#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, (1ll << 31) - 1);
    //dp[i]表示，i的所有的超集AND起来的结果
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[x] = x;
    }
    for(int i = n; i >= 0; i--)
    {
        for(int bit = 0; bit <= 20; bit++)
        {
            //枚举恰好多一位的超集
            int j = i | (1ll << bit);
            if(j > n)
            {
                continue;
            }
            dp[i] = dp[i] & dp[j];
        }
    }

    for(int mex = 1; mex <= n; mex++)
    {
        if(dp[mex] > mex)
        {
            cout << mex << endl;
            return;
        }
    }
    cout << n + 1 << endl;
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