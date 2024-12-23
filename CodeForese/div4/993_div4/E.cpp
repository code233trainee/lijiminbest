#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    // ll r = 1;
    // while(r <= r2 / l1)
    // {
    //     auto low = max(l1, (l2 + r - 1) / r);
    //     auto high = min(r1, r2 / r);
    //     if(low <= high)
    //     {
    //         ans += high - low + 1;
    //     }
    //     r *= k;
    // }
    // cout << ans << "\n";
    ll kn = 1, ans = 0;
    for(int n = 0; r2 / kn >= l1; n++)
    {
        ans += max(0ll, min(r2 / kn, r1) - max((l2 - 1) / kn+1, l1)+1ll);
        kn *= k;
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