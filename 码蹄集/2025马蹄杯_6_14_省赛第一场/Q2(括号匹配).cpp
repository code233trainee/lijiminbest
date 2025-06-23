#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    ll lcnt = 0, rcnt = 0;
    for(ll i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            if(rcnt > 0)
            {
                ans += rcnt;
                rcnt--;
            }
            else
            {
                lcnt++;
            }
        }
        else
        {
            if(lcnt > 0)
            {
                lcnt--;
            }
            else
            {
                rcnt++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}