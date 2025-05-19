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
        ll cur = a[l];
        for(int i = l + 1; i <= r; i++)
        {
            cur = (cur & a[i]) << 1;
            if(cur == 0)
            {
                break;
            }
        }
        cout << cur << endl;
    }
}
int main()
{
    //不关流过不了
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}