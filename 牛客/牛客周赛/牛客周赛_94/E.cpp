#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = k + 1ll;
    while(n > 0)
    {
        if(k < 1)
        {
            break;
        }
        if(n % 2 == 0) {
            ans++;
        } else {
            if(n > 1) {
                ans += k;
            } else {
                ans++;
            }
        }
        n >>= 1;
        k--;
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