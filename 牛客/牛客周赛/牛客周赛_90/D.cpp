#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<string> a(n+1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    auto check = [&](ll mid) -> bool {
        ll C = 1;
        ll C2 = 0, C25 = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll c2 = C2, c25 = C25;
            ll n_c2 = 0, n_c25 = 0;
            for(auto &c : a[i])
            {
                if(c == '2')
                {
                    c2++;
                    n_c2++;
                }
                else if(c == '5')
                {
                    c25 += c2;
                    n_c25 += n_c2;
                }
            }
            if(c25 <= mid)
            {
                C2 = c2;
                C25 = c25;
            }
            else
            {
                if(n_c25 > mid)
                {
                    return 0;
                }
                C++;
                C2 = n_c2;
                C25 = n_c25;
            }
        }
        return C <= k;
    };

    ll l = 0, r = 1e15;
    while(l < r)
    {
        ll mid = (l + r) / 2;
        if(check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
}
int main()
{
    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}