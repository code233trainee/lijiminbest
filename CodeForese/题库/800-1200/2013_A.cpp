// https://codeforces.com/problemset/problem/2013/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if(x >= y)
    {
        cout << (n + (y - 1)) / y << endl;
    }
    else
    {
        cout << (n + (x - 1)) / x << endl;
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