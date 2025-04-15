#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll check(ll a)
{
    ll count = 0;
    while(a)
    {
        ll b = a%10;
        a /= 10;
        if(b == 6)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        a[i] = check(b);
    }
    sort(a.begin(), a.end());
    ll l = 0, r = n - 1;
    if(a[0] >= 6)
    {
        cout << n;
        return 0;
    }
    ll cnt = 0;
    while(l < r)
    {
        if(a[r] >= 6)
        {
            cnt++;
            r--;
        }
        else
        {
            if(a[l] + a[r] >= 6)
            {
                cnt++;
                r--;
                l++;
            }
            else if(l + 1 < r && a[l] + a[l+1] + a[r] >= 6)
            {
                cnt++;
                l += 2;
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    cout << cnt;
    return 0;
}