#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
//异或是相同为0，相异为1
void solve()
{
    i64 x;
    cin >> x;
    // x不能等于2的幂             或者2的幂-1
    // 选择的v要严格小于x
    if((x & (x - 1) == 0) || (x & (x + 1) == 0))
    {
        cout << -1 << endl;
        return;
    }
    i64 v = 1;
    while(v <= x)
    {
        v <<= 1;
    }
    v >>= 1;
    v--;
    //三角形判断
    if(x + v > (x ^ v) && x + (x^v) > v && v + (x^v) > x)
    {
        cout << v << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}