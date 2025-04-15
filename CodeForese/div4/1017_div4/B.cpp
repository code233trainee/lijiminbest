#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int cnt = n - m;
    if(m == n)
    {
        cout << l << " " << r << "\n";
        return;
    }
    int ansr = max(0, r - cnt);
    cnt -= r;
    if(cnt <= 0)
    {
        cout << l << " " << ansr << "\n"; 
    }
    else
    {
        cout << l + cnt << " " << ansr << "\n";
    }
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