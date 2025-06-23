#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int t = 0;
    if(x1 >= x2 + a || x2 >= x1 + a)
    {
        if(abs(x1 - x2) % a == 0)
        {
            cout << "Yes\n";
            return;
        }
    }
    else
    {
        t++;
    }

    if(y1 >= y2 + b || y2 >= y1 + b)
    {
        if(abs(y1 - y2) % b == 0)
        {
            cout << "Yes\n";
            return;
        }
    }
    else
    {
        t++;
    }
    cout << (t == 2 ? "Yes" : "No") << endl;
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