#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if(n % 2 == 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << n << " ";
        for(int i = 1; i <= n-1; i++)
        {
            cout << i << " \n"[i == n-1];
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