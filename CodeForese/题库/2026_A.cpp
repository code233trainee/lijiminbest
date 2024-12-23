#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll x, y, z;
    cin >> x >> y >> z;
    int m = min(x, y);
    //每次就选择能够选择的最大的长度
    cout << "0 0 " << m << " " << m <<"\n";
    cout << "0 " << m << " " << m << " 0" << "\n";
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