#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    if(s.length() <= 2)
    {
        cout << "NO\n";
        return;
    }
    if(s[0] == '1' && s[1] == '0')
    {
        if(s.length() == 3)
        { 
            if(s[2] >= '2')
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if(s[2] != '0')
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
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
}