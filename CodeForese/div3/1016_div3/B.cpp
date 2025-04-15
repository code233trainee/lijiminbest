#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int cnt  = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] > '0')
        {
            j = i;
            cnt++;
        }
    }
    cout << cnt + s.size() - j - 2<< endl;
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