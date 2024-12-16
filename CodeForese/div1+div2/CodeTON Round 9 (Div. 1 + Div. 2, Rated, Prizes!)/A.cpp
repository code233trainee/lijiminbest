#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << 1 + i*2 << " \n"[i == n-1]; 
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