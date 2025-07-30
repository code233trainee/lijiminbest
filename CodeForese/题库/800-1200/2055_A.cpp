// https://codeforces.com/problemset/problem/2055/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if(abs(a - b) % 2 == 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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