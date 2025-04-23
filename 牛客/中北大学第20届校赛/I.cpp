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
    ll x, a, b;
    cin >> x >> a >> b;
    
    ll g = gcd(a, b);
    if(x % g == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}