#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < 425 && (b < 60 || c < 60 || d < 60))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}