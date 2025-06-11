#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if(n < m)
    {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < m; i++)
    {
        cout << s[i];
    }
    cout << "\n";
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