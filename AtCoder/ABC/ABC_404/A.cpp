#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    vector<bool> a(26, false);
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        a[s[i]-'a'] = true;
    }
    for(int i = 0; i < 26; i++)
    {
        if(!a[i])
        {
            cout << char(i +'a') << endl;
            return;
        }
    }
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