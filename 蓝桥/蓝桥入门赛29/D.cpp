#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll odd = 0, even = 0;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if(x % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    ll ans = 0;
    if((even >= 2))
    {
        if((odd % 2 == 0))
        {
            ans += (even - 1) * even / 2;
        }
    }
    if(even >= 1 && odd >= 1)
    {
        if((odd - 1) % 2 == 1)
        {
            ans += odd * even;
        }
    }
    if(odd >= 2)
    {
        if((odd - 2) % 2 == 0)
        {
            ans += (odd - 1) * odd / 2;
        }
    }
    cout << ans << endl;
    return 0;
}