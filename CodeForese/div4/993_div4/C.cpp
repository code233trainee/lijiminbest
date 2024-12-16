#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int row1 = min(a, m) + min(c, max(0, m - a));
    int row2 = min(b, m) + min(c - min(c, max(0, m - a)), max(0, m - b));
    int ans = row1 + row2;
    cout << ans << "\n";
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