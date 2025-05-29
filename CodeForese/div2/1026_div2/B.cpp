#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    bool ok = false;
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == '(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if(!cnt)
        {
            ok = true;
        }
    }
    if(ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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