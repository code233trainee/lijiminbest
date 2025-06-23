#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x;
    cin >> x;
    int n = 200;
    vector<int> dp(n+1);
    dp[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; i + j * j - 1 <= n; j++)
        {
            dp[i + j * j - 1] |= dp[i];
        }
    }
    if(x >= 30)
    {
        cout << "Yes\n";
    }
    else
    {
        if(dp[x])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}