#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    char c = ((s[0] > s[2]) ? '>' : (s[0] == s[2]) ? '=' : '<');
    s[1] = c;
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}