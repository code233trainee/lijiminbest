#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    if(n <= 1)
    {
        cout << "-1\n";
        return;
    }
    ll sum = n * (n + 1) / 2;
    if(sum % 2 == 1)
    {
        cout << "-1\n";
    }
    else
    {
        ll k = sum / 2;
        vector<ll> ans;
        vector<bool> a(n+1);
        ll res = 0;
        for(ll i = n; i >= 1; i--)
        {
            if(res + i <= k)
            {
                ans.push_back(i);
                a[i] = true;
                res += i;
                if(res == k)
                {
                    break;
                }
            }
        }
        for(ll i = 1; i <= n; i++)
        {
            if(!a[i])
            {
                ans.push_back(i);
            }
        }
        for(ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}