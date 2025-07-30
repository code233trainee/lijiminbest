#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 1; i < n; i++)
    {
        a[i] = (a[i-1] + a[i]) / 2;
        ans = a[i];
    }
    cout << ans << endl;
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
