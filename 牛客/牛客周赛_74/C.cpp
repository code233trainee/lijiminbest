#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll m, n;
    cin >> n >> m;
    while(m > 0 && n > 2)
    {
        //ceil是向上取整函数
        n = ceil(sqrt(n));
        m--;
    }
    if(m > 0)
    {
        n -= m;
    }
    cout << n << "\n";
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