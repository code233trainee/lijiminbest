// https://codeforces.com/problemset/problem/2075/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    if(n % 2 == 1)
    {
        n -= k;
        if(n <= 0)
        {
            cout << "1\n";
        }
        else
        {
            cout << (n + (k-2)) / (k-1) + 1 << "\n";
        }
    }
    else
    {
        cout << (n + (k-2)) / (k-1) << "\n";
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