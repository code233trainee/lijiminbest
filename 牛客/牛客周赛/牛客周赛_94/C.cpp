#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x;
    cin >> x;
    if(((x - 1) & x) == 0)
    {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    while(x)
    {
        x = x >> 1;
        cnt++;
    }
    ll y = 1ll << cnt;
    cout << y << endl;
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