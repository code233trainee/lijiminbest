#include <bits/stdc++.h>
void solve()
{
    int l, r, a, b;
    std::cin >> l >> r >> a >> b;
    int ans = std::min(r,b) - std::max(l,a);
    if(ans < 0)
    {
        ans = 1;
    }
    else
    {
        ans += (l != a);
        ans += (r != b);
    }
    std::cout << ans << "\n";
}
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}