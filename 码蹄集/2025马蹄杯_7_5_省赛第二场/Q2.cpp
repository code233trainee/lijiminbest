#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
void solve()
{
    ll n;
    cin >> n;
    ll sum = 1;
    for(int i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        k %= mod;
        sum *= k;
        sum %= mod;
    }
    cout << sum % mod << endl;
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