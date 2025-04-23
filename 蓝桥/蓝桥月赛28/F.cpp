#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll temp = min(a, c);
    ll ans = 0;
    ans += temp * 2;
    a -= temp;
    c -= temp;
    ans += (c / 2);
    ans += (b / 2) * 2;
    b = b % 2;
    temp = min(a, b);
    ans += temp;
    a -= temp;
    b -= temp;
    cout << ans << "\n";
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