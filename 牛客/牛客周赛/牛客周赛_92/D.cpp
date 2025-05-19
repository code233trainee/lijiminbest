#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll k;
    cin >> k;
    ll n = k + 1;
    ll x = -1, y = -1;
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            x = i;
            y = n / i;
            break;
        }
    }
    if(x == -1)
    {
        cout << "-1\n";
    }
    else
    {
        ll a = x - 1;
        ll b = y - 1;
        ll p = a + b;
        ll q = a * b;
        cout << p << " " << q << "\n";
    }
    return 0;
}