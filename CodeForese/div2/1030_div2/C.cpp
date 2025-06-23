#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> all;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= 61; j++)
        {
            if((a[i] >> j) & 1)
            {
                ans++;
                continue;
            }
            all.push_back(j);
        }
    }
    sort(all.begin(), all.end());
    for(auto z : all)
    {
        auto need = 1ll << z;
        if(k >= need)
        {
            k -= need;
            ans++;
        }
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