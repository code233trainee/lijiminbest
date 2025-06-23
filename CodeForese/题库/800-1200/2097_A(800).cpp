// https://codeforces.com/problemset/problem/2067/A
// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int x, y;
    cin >> x >> y;
    if(x + 1 >= y && (x + 1 - y) % 9 == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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