#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 1e9; i++)
    {
        if(i * 2.5 == n)
        {
            cout << "Yes\n";
            break;
        }
        else if(i * 2.5 > n)
        {
            cout << "No\n";
            break;
        }
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