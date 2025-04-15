#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s, t;
    cin >> t >> s;
    int n = s.size();
    if(s[0] != t[0] || s[n-1] != t[n-1])
    {
        cout << "-1\n";
        return;
    }
    int cnt = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(s[i] != t[i])
        {
            if(s[i-1] == s[i+1])
            {
                cnt++;
                continue;
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << cnt << "\n";
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