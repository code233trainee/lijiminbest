#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, s, e, d;
    cin >> n >> s >> e >> d;
    ll ans = 0;
    ll r = (s - 1 + d) % n;
    r++;
    ll l = (s - 1 - d + n) % n;
    l++;
    if(e == s)
    {
        cout << 0 << endl;
        return 0;
    }
    if(e > s)
    {
        ans = e - s;
        if(e > r)
        {
            ans = min(ans, e - r);
        }
        else
        {
            ans = min(ans, n - (r - e));
        }
        if(e > l)
        {
            ans = min(ans, e - l);
        }
        else
        {
            ans = min(ans, n - (l - e));
        }
    }
    else
    {
        ans = n - (s - e);
        if(e > r)
        {
            ans = min(ans, e - r);
        }
        else
        {
            ans = min(ans, n - (r - e));
        }
        if(e > l)
        {
            ans = min(ans, e - l);
        }
        else
        {
            ans = min(ans, n - (l - e));
        }
    }
    // ans = min(ans, min(abs(r - e), n - abs(r - e)));
    // ans = min(ans, min(abs(l - e), n - abs(l - e)));
    cout << ans << endl;
    return 0;
}