#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    double t1x = (bx+cx)/2, t1y = (by+cy)/2;
    double t2x = (ax+cx)/2, t2y = (ay+cy)/2;
    double t3x = (bx+ax)/2, t3y = (by+ay)/2;
    if((ax == 0 && t1x == 0) || 
       (ay == 0 && t1y == 0) ||
       (bx == 0 && t2x == 0) ||
       (by == 0 && t2y == 0) ||
       (cx == 0 && t3x == 0) ||
       (cy == 0 && t3y == 0))
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