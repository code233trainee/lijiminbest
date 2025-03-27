#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    if (s.length() >= 2) 
    {
        s.replace(s.length() - 2, 2, "i");
    }
    cout << s << "\n";
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