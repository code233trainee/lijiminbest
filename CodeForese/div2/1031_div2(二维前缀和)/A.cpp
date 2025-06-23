#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int ans = 0;
    if(x > y)
    {
        swap(a, b);
        swap(x, y);
    }
    ans += k >= a ? (k - a) / x + 1 : 0;
    k -= ans * x;
    ans += k >= b ? (k - b) / y + 1 : 0;
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