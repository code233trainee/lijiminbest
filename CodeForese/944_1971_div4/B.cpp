#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    bool isok = false;
    if(n == 1)
    {
        cout << "NO" << "\n";
        return;
    }
    else
    {
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i-1])
            {
                char c = s[i];
                s[i] = s[i-1];
                s[i-1] = c;
                isok = true;
                break;
            }
        }
        if(isok)
        {
            cout << "YES" << endl;
            cout << s << endl;
        }
        else
        {
            cout << "NO\n";
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
}