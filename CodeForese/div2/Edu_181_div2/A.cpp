#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    string l = "", r = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'T')
        {
            l += s[i];
        }
        else
        {
            r += s[i];
        }
    }
    cout << l + r << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}