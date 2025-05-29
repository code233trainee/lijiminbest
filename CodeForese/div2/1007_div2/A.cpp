#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int k;
    cin >> k;
    if((k - 1) % 3 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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