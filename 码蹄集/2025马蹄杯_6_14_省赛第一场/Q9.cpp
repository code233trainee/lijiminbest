#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<ll> ms;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(auto z : ms)
    {
        if(k == 0)
        {
            break;
        }
        if(z == 1)
        {
            ans += 1;
            k--;
            continue;
        }
        ll temp = min(k, z);
        ll now = z - temp;
        ll sum = (z * (z + 1) / 2) - (now * (now + 1) / 2);
        k -= temp;
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}