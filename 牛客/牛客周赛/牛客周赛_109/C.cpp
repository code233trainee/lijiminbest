#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll x3, y3;
    if(x1 == x2)
    {
        x3 = x1 + 2;
        y3 = y1;
    }
    else if(y1 == y2)
    {
        x3 = x1;
        y3 = y1 + 2;
    }
    else
    {
        if(x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        x3 = x2 - 2*(x2 - x1);
        y3 = y2;
    }
    cout << x3 << " " << y3 << endl;
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