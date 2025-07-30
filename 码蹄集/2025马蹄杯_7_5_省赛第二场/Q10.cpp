#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b;
    cin >> a >> b;
    if((a*2 + b*2) % 4 != 0)
    {
        cout << "YES\n";
    }
    else
    {
        if(a == b && a % 2 == 1)
        {
            cout << "NO\n";
        }
        else
        {
            if(a % 2 == 1 && b % 2 == 1)
            {
                cout << "NO\n";
                return;
            }
            cout << "YES\n";
        }
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}