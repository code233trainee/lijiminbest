#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    if(n < 4)
    {
        cout << "1\n";
        return;
    }
    ll i = 1;
    while(n/4)
    {
        n /= 4; 
        ans = (n >= 0) << i;
        i++;
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