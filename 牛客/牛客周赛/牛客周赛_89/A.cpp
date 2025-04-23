#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    if(n&1)
    {
        cout << n/2+1 << endl;
    }
    else
    {
        cout << n/2 << endl;
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}