#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll base, c0, mod;
    cin >> base >> c0 >> mod;
    if(mod == 1)
    {
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++)
        {
            cout << 0 << endl;
        }
        return;
    }

    ll curr = c0;
    unordered_map<ll, ll> vis, vis_sum;
    vector<ll> a;
    ll sum = 0;
    ll tim = 0;
    ll T = 0, T_sum = 0;
    while(true)
    {
        if(vis.count(curr))
        {
            T = tim - vis[curr];
            T_sum = (sum - vis_sum[curr] + curr + mod) % mod;
            break;
        }
        vis[curr] = tim;
        sum = (sum + curr) % mod;
        a.emplace_back(sum);
        vis_sum[curr] = sum;
        curr = ksm(base, curr, mod);
        tim++;
    }
    
    ll q;
    cin >> q;
    while(q--)
    {
        ll k;
        cin >> k;
        if(k < vis[curr])
        {
            cout << ((a[k] - c0) % mod + mod) % mod << endl;
        }
        else
        {
            ll c = k - (vis[curr] - 1);
            ll ans = (c / T) % mod * T_sum % mod;
            c %= T;
            ans = (ans + a[c + vis[curr] - 1]) % mod;

            cout << ((ans % mod + mod - c0) % mod + mod) % mod << endl;
        }
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}