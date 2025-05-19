#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b)
    {
        cout << "Win\n";
    }
    else if(c > b)
    {
        cout << "WIN\n";
    }
    else
    {
        cout << "nowin\n";
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