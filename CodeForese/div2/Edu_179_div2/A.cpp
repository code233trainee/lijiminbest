#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x;
    cin >> x;
    // scanf("%d",x);
    ll a = 0, b = 0, c = 0;
    vector<ll> v(3, 1);
    ll ans = 3;
    if(x == 1)
    {
        cout << ans << "\n";
        return;
    }
    while(true)
    {
        sort(v.begin(), v.end());
        if(v[1] * 2 + (v[1] % 2) >= x)
        {
            ans += 3;
            break;
        }
        ans += 1;
        v[1] = v[1] * 2 + (v[1] % 2);
    }
    cout << ans-1 << endl;
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