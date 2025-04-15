#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll total = 0;
    for(int i = 0; i <= m; i++)
    {
        total += (ll)(pow(n, i));
        if(total > 1e9)
        {
            cout << "inf";
            return;
        }
    }
    cout << total;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}