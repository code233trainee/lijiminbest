#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int mn = INT_MAX;
    for(int i = 0; i < s.size(); i++)
    {
        mn = min(mn, s[i]- '0');
    }
    cout << mn << endl;
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