#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, l, r;
    cin >> a >> l >> r;
    cout << (a + r - 1) / r << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}