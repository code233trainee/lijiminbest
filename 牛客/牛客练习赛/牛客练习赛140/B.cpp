#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, s;
    cin >> n >> s;
    if(s == 1)
    {
        cout << "0\n";
        return;
    }
    ll ans = s - 1;
    for(ll i = n / s; i <= n / s + 1; i++)
    {
        ans = min(ans, i + abs(n / i - s));
    }
    cout << ans << "\n";
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