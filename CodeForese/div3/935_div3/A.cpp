#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll ans = a;
    if(b%3 == 0)
    {
        ans += (b / 3) + ((c+2) / 3);
        cout << ans << endl; 
    }
    else if((b%3 + c) >= 3)
    {
        ans += (b / 3 + 1) + ((c - (3 - b%3))+2) / 3;
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
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