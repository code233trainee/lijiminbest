#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            ll len = 0;
            while(len <= m)
            {
                if(s[i] == '0')
                {
                    len++;
                }
                else
                {
                    break;
                }
                if(len >= m)
                {
                    if(i+k > n)
                    {
                        fill(s.begin() + i, s.end(), '1');    
                    }
                    else
                    {
                        fill(s.begin() + i, s.begin() + i + k, '1');
                    }
                    ans++;
                    break;
                }
                else
                {
                    i++;
                }   
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
}