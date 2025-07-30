#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll g = gcd(a, b);
    ll t = max(((a + k - 1) / k), ((b + k - 1) / k));
    if(g >= t)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}