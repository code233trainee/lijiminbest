#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    int n;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '2')
        {
            cnt++;
        }
    }
    if(cnt == 0 || cnt == n)
    {
        cout << "0\n";
        return;
    }
    int ans = 0;
    for(int i = 0; i < n - cnt; i++)
    {
        if(s[i] == '2')
        {
            ans++;
        }
    }
    cout << ans;
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