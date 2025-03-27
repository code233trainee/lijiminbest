#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if( l == r && r == d && d == u )
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
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