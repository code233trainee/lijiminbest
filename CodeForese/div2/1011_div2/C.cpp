#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x, y;
    cin >> x >> y;
    if(x == y)
    {
        cout << "-1\n";
    }
    else
    {
        // 只k足够大，那么较小的那个就与最大数没有公共位
        cout << ((1ll << 48) - max(x, y)) << endl;
    }
}
int main()
{
    // 二进制中对于任意两个数都有 a+b=(a⊕b)+2⋅(a&b)
    // 此题就化简为了(x+k)&(y+k)=0
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}