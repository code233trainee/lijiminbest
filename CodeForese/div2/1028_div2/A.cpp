#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int k = min(a, c);
    int t = min(b, d);
    if(k >= t)
    {
        cout << "Gellyfish\n";
    }
    else
    {
        cout << "Flower\n";
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
