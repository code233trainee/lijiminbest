#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 200005
ll gcd(ll a, ll b) 
{
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll m = *(std::max_element(a.begin(), a.end()));
    vector<ll> cnt(m+1);
    for(auto z : a)
    {
        cnt[z]++;
    }
    ll ans = 0;
    for(ll g = 1; g <= m; g++)
    {
        for(ll i = g; i <= m; i += g)
        {
            ll j = i^g;
            if(i < j && gcd(i, j) == g && j <= m)
            {
                ans += cnt[i] * cnt[j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}