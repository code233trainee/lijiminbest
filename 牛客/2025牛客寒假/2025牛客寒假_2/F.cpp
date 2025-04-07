#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    //还是那个公式：对于任意的两个二进制数，都有a+b = a^b + 2(a&b)
    ll l, r;
    cin >> l >> r;
    cout << r - l + 1 << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}