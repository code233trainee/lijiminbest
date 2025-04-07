#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n = 0;
ll check(ll k)
{
    
    ll cnt = 0;
    while(k)
    {
        k /= 10;
        cnt++;
    }
    return cnt;
}
void solve()
{
    ll a;
    cin >> a;
    n = check(a);
    ll ans = -1;
    for(int i = 1; i < n; i++)
    {
        int j = i;
        ll c = 0, b = 0; 
        ll num = 0;
        ll k = a;
        while(j)
        {
            c += (k % 10) * (ll)(pow(10, num));
            b = k / 10;
            k /= 10;
            j--; 
            num++;
        }
        ans = max(ans, c + b);
    }
    cout << ans << "\n";
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