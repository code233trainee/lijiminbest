#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll ans = 1;
        ll n, m, k;
        cin >> n >> m >> k;
        
        ll lc = k, rc = k;
        while(1)
        {
            bool ok = false;
            lc = (lc-1) * m + 2;
            rc = rc * m + 1;
            if(lc > n)
            {
                break;
            }
            if(rc >= n)
            {
                ok = true;
                rc = n;
            }
            ans += rc - lc + 1;
            if(ok)
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}