#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    int cnt = 0;
    char c = '0';
    for(int i = 1; i <= n; i++)
    {
        if(s[i] != c)
        {
            c = s[i];
            cnt++;
        }
    }
    if(cnt >= 3)
    {
        cnt -= 2;
    }
    else if(cnt == 2)
    {
        cnt = 1;
    }
    cout << cnt + n << endl;
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