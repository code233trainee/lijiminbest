#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    ll ans = 0;
    ll mx = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        if((s[i] - '0') ^ j)
        {
            ans += c[i];
            mx = max(mx, c[i]);
            j ^= 1;
        }
    }
    cout << ans - mx << endl;
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