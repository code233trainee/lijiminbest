#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 100;
char ch[N];

ll ksm(ll x, ll y)
{
    ll res = 1;
    for(;y ; y >>= 1 , x = x * x % mod)
    {
        if(y&1)
        {
            res = res * x % mod;
        }
    }
    return res;
}
void solve()
{
    ll l, r, k;
    cin >> l >> r >> k;
    ll wd = (9/k);
    ll now = (((ksm(wd + 1, r - l) - 1) % mod) + mod) % mod;
    now = ksm(wd + 1, l) % mod * now % mod;
    cout << now << "\n";
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