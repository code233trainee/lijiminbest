#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, y;
    cin >> x >> y;
    //((y + 1) / 2)是我们至少需要的屏幕数量
    //(x + y * 4 + 14) / 15是
    int ans = max(((y + 1) / 2), (x + y * 4 + 14) / 15);
    //我觉得是不是与y+1/2的原理是一样的
    //加上(除数减一)
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}