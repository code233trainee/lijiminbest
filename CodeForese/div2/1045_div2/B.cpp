#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // if(k == 1)
    // {
    //     for(ll i = 0; i < n; i++)
    //     {
    //         a[i] += (a[i] % (k + 1)) * k;
    //     }
    // }
    // else
    // {
    //     for(ll i = 0; i < n; i++)
    //     {
    //         a[i] += (a[i] % (k)) * k;
    //     }
    // }
    
    for(int i = 0; i < n; i++)
    {
        a[i] += (a[i] % (k + 1)) * k;
    }
    for(ll i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}