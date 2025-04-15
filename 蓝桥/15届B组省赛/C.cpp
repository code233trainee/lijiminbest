#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll a)
{
    ll cnt = 1;
    while(a)
    {
        ll b = a % 10;
        a /= 10;
        if(cnt % 2 == 0)
        {
            if(b % 2 != 0)
            {
                return false;
            }
        }
        else
        {
            if(b % 2 != 1)
            {
                return false;
            }
        }
        cnt++;
    }
    return true;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(check(i))
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}