#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, m;
    cin >> a >> b >> m;
    ll ans = m / a + m / b + 2;
    cout << ans << endl;
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