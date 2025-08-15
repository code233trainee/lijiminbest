#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int l, r;
    cin >> l >> r;
    cout << ((r + 1) / 2 - l / 2) / 2 << endl;
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