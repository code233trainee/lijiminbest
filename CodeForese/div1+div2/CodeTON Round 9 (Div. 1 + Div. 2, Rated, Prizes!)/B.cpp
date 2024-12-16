#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1)
    {
        cout << "-1\n";
        return;
    }
    string res = "-1";
    for(int i = 0; i < n; i++)
    {
        if(s[i] == s[i+1])
        {
            res = s.substr(i, 2);
            break;
        }
    }
    for(int i = 0;i < n - 2; i++)
    {
        if(res == "-1" && s[i] != s[i+2])
        {
            res = s.substr(i, 3);
            break;
        }
    }
    cout << res << "\n";
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