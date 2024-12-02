#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x, y;
    cin >> x >> y;
    cout << (x <= y ? x : y) << " " << (x >= y ? x : y) << endl;
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