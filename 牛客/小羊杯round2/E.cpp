#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 3 + 3;
    if(2*a > b)
    {
        ans++;
    }
    if(2*a > c)
    {
        ans++;
    }
    if(2*b > c)
    {
        ans++;
    }
    if(a + b > c)
    {
        ans++;
    }
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
    return 0;
}