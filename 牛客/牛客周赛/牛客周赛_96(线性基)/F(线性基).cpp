#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    vector<ll> base(60);
    auto insert = [&](ll x) -> void {
        for(ll j = 59; j >= 0; j--)
        {
            if(x >> j & 1)
            {
                if(base[j])
                {
                    x ^= base[j];
                }
                else
                {
                    base[j] = x;
                    break;
                }
            }
        }
    };

    auto contains = [&](ll x) -> bool {
        for(ll j = 59; j >= 0; j--)
        {
            if(x >> j & 1)
            {
                if(base[j])
                {
                    x ^= base[j];
                }
            }
        }
        return x == 0;
    };

    ll n;
    cin >> n;
    for(ll i = 1, x; i <= n; i++)
    {
        cin >> x;
        insert(x);
    }
    ll mex = 0;
    for(int i = 0; i <= 60; i++)
    {
        if(!contains(1ll << i))
        {
            mex = 1ll << i;
            break;
        }
    }

    cout << mex << endl;
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