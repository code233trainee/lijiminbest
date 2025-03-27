#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int j = n - 1;
    ll cnt = 0;
    ll cont = 1;
    ll mi = INT64_MAX;
    while(j >= 0)
    {
        mi = min(mi, a[j]);
        if(mi * cont >= x)
        {
            cnt++;
            cont = 1;
            j--;
        }
        else
        {
            j--;
            cont++;
        }
    }
    cout << cnt << "\n";
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