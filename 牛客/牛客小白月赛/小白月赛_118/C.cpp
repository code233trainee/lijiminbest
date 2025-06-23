#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int PHI = MOD - 1;
ll mod_pow(ll a, ll e, int m = MOD) {
    ll r = 1;
    a %= m;
    while (e) {
        if (e & 1) r = r * a % m;
        a = a * a % m;
        e >>= 1;
    }
    return r;
}
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    ll len = s.size();
    ll n_mod = n % PHI;
    ll len_mod = len % PHI;
    ll exp  = (n_mod * len_mod) % PHI;
    ll ans = (mod_pow(2, exp) - 1 + MOD) % MOD;
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
    {
        solve();
    }

    return 0;
}
