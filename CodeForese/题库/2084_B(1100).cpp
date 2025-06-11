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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0] == a[1])
    {
        cout << "Yes\n";
        return;
    }
    ll G = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] % a[0] == 0)
        {
            G = gcd(G, a[i]);
        }
    }
    if(G != a[0])
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
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