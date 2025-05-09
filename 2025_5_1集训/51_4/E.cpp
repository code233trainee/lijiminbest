// https://codeforces.com/problemset/problem/1659/B
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = "#" + s;
    vector<int> a(n+1);
    int temp = k;
    for(int i = 1; i <= n && k > 0; i++)
    {
        if(temp & 1)
        {
            if(s[i] == '1')
            {
                a[i] = 1;
                k--;
            }
        }
        else
        {
            if(s[i] == '0')
            {
                a[i] = 1;
                k--;
            }
        }
    }
    a[n] += k;
    for(int i = 1; i <= n; i++)
    {
        if(((temp - a[i]) % 2) == 1)
        {
            s[i] = '1' - (s[i] - '0');
        }
    }
    cout << s.substr(1) << endl;
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