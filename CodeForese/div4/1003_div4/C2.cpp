#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    if(n <= 1)
    {
        cout << "YES\n";
        return;
    }
    for(ll i = 1; i < n; i++)
    {
        int id = lower_bound(b.begin(), b.end(), a[i] + a[i-1]) - b.begin();
        if(id < m && (a[i] < a[i-1] || b[id] - a[i] < a[i]))
        {
            a[i] = b[id] - a[i];
        }
    }
    for(ll i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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