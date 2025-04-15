#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a;
    cin >> a;
    ll ans = 1;
    ll cnt = 0;
    bool isok = false;
    while(a)
    {
        if(!(a&1))
        {
            isok = true;
            break;
        }
        else
        {
            a = a>>1;
            cnt++;
        }
    }
    if(isok)
    {
        ans = ans << cnt;
        cout << ans << "\n";    
    }
    else
    {
        cout << "-1\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}