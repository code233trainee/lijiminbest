#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    if(a >= b)
    {
        cout << a << "\n";
        return;
    }
    int x = b - a;
    a -= x;
    int ans = max(0, a);
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