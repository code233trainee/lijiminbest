// https://codeforces.com/problemset/problem/1732/B
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int c = 0;
    int ans = 0;
    int j = 0;
    for(; j < n; j++)
    {
        if(s[j] == '1')
        {
            break;
        }
    }
    for(int i = n - 1; i > j; i--)
    {
        if(s[i] != s[i-1])
        {
            ans++;
        }
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