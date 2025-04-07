#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int ch = 0; ch < 26; ch++)
    {
        int pre = 0, suf = 0;
        for(int i = 0; i < n; i++)
        {
            //这一步才是从后缀开始求前缀
            if(s[i]-'a' != ch) continue;
            if(suf != 0)
            {
                ans = max(ans, n - i);
            }
            suf = i;
        }
        for(int i = n-1; i >= 0; i--)
        {
            //这一步是从前缀开始求后缀
            if(s[i]-'a' != ch) continue;
            if(pre != 0)
            {
                ans = max(ans, i+1);
            }
            pre = i;
        }
    }
    cout << (ans == 1 ? 0 : ans);
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

/// 以一下代码才能通过
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    int ans = 0;
    for(int ch = 0; ch < 26; ch++)
    {
        int pre = 0, suf = 0;
        for(int i = 1; i <= n; i++)
        {
            //这一步才是从后缀开始求前缀
            if(s[i]-'a' != ch) continue;
            if(suf != 0)
            {
                ans = max(ans, n - i + 1);
            }
            suf = i;
        }
        for(int i = n; i >= 0; i--)
        {
            //这一步是从前缀开始求后缀
            if(s[i]-'a' != ch) continue;
            if(pre != 0)
            {
                ans = max(ans, i);
            }
            pre = i;
        }
    }
    cout << (ans == 1 ? 0 : ans);
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