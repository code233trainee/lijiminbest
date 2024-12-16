#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll x, m;
    cin >> x >> m;
    int ans = 0;
    for(int y = 1; y <= 10*x && y <= m; y++)
    {
        int v = x ^ y;
        if(v != 0 && (x % v == 0 || y % v == 0))
        {
            ans += 1;
        }
    }
    cout << ans << "\n";
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