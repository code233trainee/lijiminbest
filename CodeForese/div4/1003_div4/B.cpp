#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    bool isok = false;
    for(int i = n-1; i > 0; i--)
    {
        if(s[i] == s[i-1])
        {
            isok = true;
            break;
        }
    }
    if(isok)
    {
        cout << "1\n";
    }
    else
    {
        cout << n << "\n";
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