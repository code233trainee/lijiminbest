#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if(l1 == b1 + b2 + b3 && l1 == l2 && l2 == l3) cout << "YES\n";
    else if(b1 == l1 + l2 + l3 && b1 == b2 && b2 == b3) cout << "YES\n";
    else if(l1 == l2 + l3 && b2 == b3 && b2 + b1 == l1) cout << "YES\n";
    else if(b1 == b2 + b3 && l2 == l3 && l1 + l2 == b1) cout << "YES\n";
    else cout << "NO\n";
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