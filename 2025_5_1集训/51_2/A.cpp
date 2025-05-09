// https://codeforces.com/problemset/problem/1861/A
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int a = 0, b = 0;
    // 13, 31
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            a = i;
        }
        if(s[i] == '3')
        {
            b = i;
        }
    }
    if(a > b)
    {
        cout << 31 << endl;
    }
    else
    {
        cout << 13 << endl;
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