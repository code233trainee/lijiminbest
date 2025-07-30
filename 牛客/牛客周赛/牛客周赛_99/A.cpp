#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i-1] && s[i] == '9')
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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