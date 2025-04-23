#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, y, a;
    cin >> x >> y >> a;
    int cnt = a%(x+y);    
    if(cnt >= x)
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
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}