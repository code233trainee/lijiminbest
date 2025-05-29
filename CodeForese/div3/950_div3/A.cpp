#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(7);
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        a[s[i]-'A']++;
    }
    int ans = 0;
    for(int i = 0; i < 7; i++)
    {
        ans += max(m - a[i], 0);
    }
    cout << ans << endl;
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