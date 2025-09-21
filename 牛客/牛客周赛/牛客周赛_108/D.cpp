#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll ksm(ll a, ll b, ll p)
{
	ll ans = 1;
	a %= p;
	while(b)
	{
		if(b & 1)
		{
			ans = (ans * a) % p;
		}
		b >>= 1;
		a = (a * a) % p;
	}
	return ans % p;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    ll ans = 0;
    ans += ((ksm(2, n, mod) - 1) - (ksm(2, odd, mod) - 1) + mod) % mod;

    cout << ans << endl; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}