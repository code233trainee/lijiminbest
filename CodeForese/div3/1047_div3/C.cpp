#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b;
    cin >> a >> b;
    if( a % 2 == 1 && b % 2 == 1)
    {
        cout << a * b + 1 << endl;
    }
    else if(a % 2 == 0 && b % 2 == 0)
    {
        cout << a * b / 2 + 2 << endl;
    }
    else if(a % 2 == 1 && b % 4 == 0)
    {
        cout << a * b / 2 + 2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}