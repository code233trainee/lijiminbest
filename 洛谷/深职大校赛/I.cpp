#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 2025;
ll qu(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for(ll i = 1; i <= n; i++)
    {
        sum += qu(3, i, mod);
        for(int j = i; j >= 2; j--)
        {
            sum -= qu(2, i - j, mod) * (i - j + 1);
        }
        sum %= mod;
    }
    cout << sum << endl;
    return 0;
}