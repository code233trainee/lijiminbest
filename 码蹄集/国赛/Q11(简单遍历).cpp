//https://www.matiji.net/exam/brushquestion/50/4693/305EE97B0D5E361DE6A28CD18C929AF0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 7;
void solve()
{
    int a, n;
    cin >> a >> n;
    vector<int> num(n);
    for(int i = 1; i <= n; i++)
    {
        num[i] = (1ll * num[i - 1] * 10 % mod + a) % mod;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = (ans + num[i]) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}