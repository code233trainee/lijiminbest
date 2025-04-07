#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
void solve()
{
    ll n, m;
    cin >> n >> m;
    if(m == 1)
    {
        cout << "1\n";
        return;
    }
    ll Min = 1e18, ans, now = 1;
    for (int i = 1; i <= 32; i++) {
        if (now >= inf / m) break;
        now *= m;
        if (abs(n - now) < Min) {
            Min = abs(n - now);
            ans = i;
        }
    }
    cout << ans << '\n';
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}