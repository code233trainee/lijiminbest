#include <bits/stdc++.h>
using namespace std;
void solve()
{
    double a;
    cin >> a;
    double b = 400/a;
    int c = b;
    cout << (c*a == 400 ? c : -1) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}