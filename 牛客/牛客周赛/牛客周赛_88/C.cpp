#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1 == (x2+x3)/2 ||
       y1 == (y2+y3)/2 ||
       x2 == (x1+x3)/2 ||
       y2 == (y1+y3)/2 ||
       x3 == (x1+x2)/2 ||
       y3 == (y1+y2)/2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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