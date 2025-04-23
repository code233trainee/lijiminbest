#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
ll quickPower(ll a, ll b)
{
	ll ans = 1, base = a;
	while(b > 0)
    {
		if(b & 1)
        {
            ans = (ans*base) % mod;
        }
        base = (base*base) % mod;
		b >>= 1;
	}
	return ans;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    if(n == k) {
        cout << 2 << endl;
        return;
    }
    cout << quickPower(2, n - (k%2 == 0)) << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}