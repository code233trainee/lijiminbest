#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == '1')
        {
            if(s[i-1] == '1')
            {
                s[i] = '0';
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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