#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    string a = "";
    int n = s.length();
    for(int i = n-1; i >= 0; i--)
    {
        if(s[i] == 'q')
        {
            a += 'p';
        }
        if(s[i] == 'p')
        {
            a += 'q';
        }
        if(s[i] == 'w')
        {
            a += 'w';
        }
    }
    cout << a << "\n";
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