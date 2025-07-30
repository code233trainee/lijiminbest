// https://codeforces.com/problemset/problem/2029/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            cnt1++;
        }
        else
        {
            cnt0++;
        }
    }
    for(int i = 0; i < n-1; i++)
    {
        if(cnt1 == 0 || cnt0 == 0)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            if(t[i] == '1')
            {
                cnt0--;
            }
            else
            {
                cnt1--;
            }
        }
    }
    cout << "YES\n";
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