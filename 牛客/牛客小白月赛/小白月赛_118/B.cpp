#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) 
{
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(gcd(a[i], a[i+1]) != 1)
        {
            ans++;
            if(i+2 < n && gcd(a[i+1], a[i+2]) != 1)
            {
                i++;
            }
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