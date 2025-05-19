#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if(n % p != 0)
    {
        cout << "YES\n";
    }
    else
    {
        if(q*(n/p) == m)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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