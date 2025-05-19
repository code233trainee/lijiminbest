#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        if(n == 1)
        {
            cout << a[1] << "\n";
            return;
        }
        ll ans = a[1];
        for(int i = 2; i <= n; i++)
        {
            ans = 2*(ans & a[i]);
        }
        cout << ans << endl;
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