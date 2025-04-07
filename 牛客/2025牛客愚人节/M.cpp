#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> a;
bool check(ll n)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == n)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = n;
    while(n)
    {
        ll c = n % 10;
        a.push_back(c);
        n /= 10;
    }
    if(check(1))
    {
        if(check(2))
        {
            ll cnt = 0;
            ll num = 0;
            for(int i = 0; i < a.size(); i++)
            {
                if(a[i] == 2)
                {
                    continue;
                }
                else
                {
                    num += a[i]*(pow(10, cnt));
                    cnt++;
                }
            }
            cout << num;
        }
        else
        {
            cout << ans;
        }
    }
    else
    {
        cout << ans;
    }
    return 0;
}