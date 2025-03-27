#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    if(n % 2 == 0)
    {
        cout << "-1\n";
        return;
    }
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = (2ll * i % n) + 1;
    }
    for(auto z : a)
    {
        cout << z << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}