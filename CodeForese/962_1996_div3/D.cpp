#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    for(int a = 1; a <= min(n, x); a++)
    {
        for(int b = 1; a * b <= n && a + b <= x; b++)
        {
            int bigC = min((n - a * b)/(a+b), x - a -b);
            ans += bigC;
        }
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
}