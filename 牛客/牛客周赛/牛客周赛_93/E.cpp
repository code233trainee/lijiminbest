#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int mod = 1e9+7;
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    ll ans = 0;
    ll s = 1;
    // 从0开始，包含了全0的情况
    // 计算
    for(int i = 0; i <= n; i++)
    {
        if(cnt[i] == 0)
        {
            break;
        }
        // 使用减法要记得防止负数(加上mod再模一次)
        s *= ksm(2ll, cnt[i], mod) - 1 + mod;
        s %= mod;
        ans += s;
        ans %= mod;
    }

    // 这里从1开始，防止重复计算全0的情况
    // 计算单个数字的情况
    for(int i = 1; i <= n; i++)
    {
        ans += ksm(2ll, cnt[i], mod) - 1 + mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
