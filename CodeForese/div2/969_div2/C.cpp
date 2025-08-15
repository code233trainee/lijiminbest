#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int d = gcd(a, b);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = v[i] % d;
    }
    sort(v.begin(), v.end());
    int res = v[n-1] - v[0];
    // int res = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        res = min(res, v[i-1] + d - v[i]);
    }
    cout << res << endl;
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