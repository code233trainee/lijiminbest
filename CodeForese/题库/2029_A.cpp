#include <bits/stdc++.h>
using namespace std;
void solve()
{
    // 我们可以按从小到大的顺序删除数字。因此，先前删除的数字不会影响将来的选择(如果是 x<y，则 x不能是 y的倍数)。
    // 因此，整数 x(l≤x≤r)当且仅当 k⋅x≤r，即 x≤⌊r/k⌋时才可以被删除
    int l, r, k;
    cin >> l >> r >> k;
    cout << max(r / k - l + 1, 0) << "\n";
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