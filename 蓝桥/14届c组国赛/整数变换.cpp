#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while(n)
    {
        ans++;
        ll a = n;
        ll b = 0;
        ll c = 0;
        while(a)
        {
            b += a%10;
            c++;
            a /= 10; 
        }
        n -= b;
        
    }
    cout << ans;
    return 0;
}