#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll a[1000009], l[1000009], r[1000009];
ll sum[41]; 
int main()
{
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
       cin >> a[i];
    }
    a[0] = a[n+1] = 1;
    l[0] = r[n+1] = 1;
    for(int i = 1; i <= n; i++)
    {
        sum[a[i]] += l[i-1];
        sum[a[i]] %= mod;
        l[i] = sum[a[i]];
    }
    memset(sum, 0, sizeof(sum));
    for(int i = n; i >= 1; i--)
    {
        sum[a[i]] += r[i+1];
        sum[a[i]] %= mod;
        r[i] = sum[a[i]];
    }
    ll ans = 0;
    for(int i = 1; i <= 40; i++)
    {
        ll qaq = 0, res = 0;
        for(int j = 1; j <= n; j++)
        {
            if(a[j] == i)
            {
                res += l[j-1];
                res %= mod;
                res *= a[j];
                res %= mod;
                qaq += (r[j+1] * res % mod);
                qaq %= mod;
            }
            else
            {
                res *= a[j];
                res %= mod;
            }
        }
        ans += qaq;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}