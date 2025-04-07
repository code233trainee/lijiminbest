#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < k; i++) cin >> c[i];
    ll ans = INT64_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0;  j < m; j++)
        {
            for(int p = 0; p < k; p++)
            {
                ans = max(ans, ((a[i]*b[j])%c[p]));
            }
        }
    }
    cout << ans;
    return 0;
}