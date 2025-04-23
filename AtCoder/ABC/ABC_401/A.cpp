#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    string ans;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += s[i];
        }
    }
    cout << ans;
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