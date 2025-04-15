#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(30);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        for(int j = 0; j < 30; j++)
        {
            cnt[j] += ((a[i] >> j) & 1);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll total = 0;
        for(int j = 0; j < 30; j++)
        {
            bool check = ((a[i] >> j) & 1);
            if(check)
            {
                total += (1 << j) * (n - cnt[j]);
            }
            else
            {
                total += (1 << j) * cnt[j];
            }
        }
        ans = max(ans, total);
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