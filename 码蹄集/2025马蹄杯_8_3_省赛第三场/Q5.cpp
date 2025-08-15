#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    while(q--)
    {
        string t;
        cin >> t;
        int k = t.size();
        int pos = 0;
        for(int i = 0; i < n; i++)
        {
            if(pos != k && s[i] == t[pos])
            {
                pos++;
            }
        }
        if(pos == k)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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