#include <bits/stdc++.h>
using namespace std;
// lcp:字符串的最长公共前缀
int lcp(string &s, string &t)
{
    int i = 0;
    while(i < s.size() && i < t.size() && t[i] == s[i])
    {
        i++;
    }
    return i;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

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