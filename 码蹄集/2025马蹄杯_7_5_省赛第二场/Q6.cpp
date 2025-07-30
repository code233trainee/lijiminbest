#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = "#" + s;
    set<string> se;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            se.insert(s.substr(j, i));
        }
    }  
    cout << se.size() << endl;
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