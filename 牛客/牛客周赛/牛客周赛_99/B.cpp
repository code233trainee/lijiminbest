#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, (int)s[i]);
    }
    cout << mx << endl;
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