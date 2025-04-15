#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) 
{
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    ll c = (ll)pow(a, b);
    ll cnt = 0;
    for(ll i = 1; i <= c; i++)
    {
        if(gcd(i, c) == 1)
        {
            cnt++;
        }
    }
    cout << cnt % 998244353;
    return 0;
}