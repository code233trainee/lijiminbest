#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c -= a;
    d -= b;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    if(((b + 1) / 2) <= (a + 1) && ((d + 1) / 2) <= (c + 1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}