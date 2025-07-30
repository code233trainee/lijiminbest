#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    for(int i = 1; i <= 50; i++)
    {
        if(i % 2 == 1)
        {
            cout << i << " ";
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