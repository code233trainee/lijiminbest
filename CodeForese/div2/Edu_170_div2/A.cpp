#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s, t;
    cin >> s >> t;
    int ss = s.size();
    int st = t.size();
    int cnt = 0;
    for(int i = 0; i < min(st, ss); i++)
    {
        if(s[i] == t[i])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    int ans = ss + (st - cnt) + (cnt > 0);
    cout << ans << "\n";
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