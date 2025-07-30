// https://codeforces.com/problemset/problem/2057/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    cout << max(n, m) + 1 << endl;
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