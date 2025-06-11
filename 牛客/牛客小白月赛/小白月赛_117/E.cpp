#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    set<ll> s;
    vector<ll> a;
    for(ll i = 1; i <= n; i++)
    {
        // int x;
        ll x;
        cin >> x;
        a.push_back(x);
        s.insert(x);
    }
    if(s.size() == 1)
    {
        cout << "0\n";
    }
    else
    {
        ll cnt = 0;
        ll nn = s.size();
        ll total = 0;
        ll ans = 0;
        for(auto &z : s)
        {
            if(z == 0)
            {
                cnt++;
                continue;
            }
            else
            {
                if(z - total <= 0)
                {
                    cnt++;
                    continue;
                }
                if(cnt > 0)
                {
                    ll k = z - total;
                    total += (k + (nn - cnt - 1 + 1)) / (nn - cnt + 1) * (nn - cnt + 1);
                    ans +=  (k + (nn - cnt - 1 + 1)) / (nn - cnt + 1);
                    cnt++;
                }
                else
                {
                    ll k = z - total;
                    total += (k + (nn - cnt - 1)) / (nn - cnt) * (nn - cnt);
                    ans += (k + (nn - cnt - 1)) / (nn - cnt);
                    cnt++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}