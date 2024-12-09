#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if(n == 2 || n == 3 || n == 4)
    {
        cout << 2 << endl;
        return;
    }
    ll cnt = 4;
    ll ans = 2;
    while(n > cnt)
    {
        cnt = cnt * 2 + 2;
        ans++;
    }
    cout << ans << endl;
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