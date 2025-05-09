#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b || b == c)
    {
        cout << "NO\n";
        return;
    }
    if(a != 0 && a == c)
    {
        cout << "NO\n";
        return;
    }
    if((a != 0 && b != 0) || (b != 0 && c != 0))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}