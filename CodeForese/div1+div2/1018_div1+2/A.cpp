#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = '#' + s;
    vector<int> a(n+1);
    int mn = 1;
    int mx = n;
    for(int i = n - 1; i >= 1; i--)
    {
        if(s[i] == '<')
        {
            a[i+1] = mn;
            mn++;
        }
        if(s[i] == '>')
        {
            a[i+1] = mx;
            mx--;
        }
    }
    a[1] = mn;
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }
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