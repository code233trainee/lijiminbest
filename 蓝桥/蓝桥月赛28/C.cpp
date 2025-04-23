#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;
void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    unordered_set<int> us;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(auto z : a)
    {
        if(us.find(z) == us.end())
        {
            ans++;
            us.insert(z+d);
        }
    }
    cout << ans;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}