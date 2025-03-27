#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int l, r;
    cin >> l >> r;
    if(l == 1)
    {
        cout << max(1, r - l) << "\n";
    }
    else
    {
        cout << r - l << "\n";
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