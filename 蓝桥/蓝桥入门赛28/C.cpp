#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    while(q--)
    {
        ll L, R;
        cin >> L >> R;
        ll cnt = R - L + 1;
        if(cnt % 2 == 0)
        {
            ans += -1 * (cnt/2);
        }
        else
        {
            ans += L;
            ans += cnt/2;
        }
    }
    cout << ans;
    return 0;
}