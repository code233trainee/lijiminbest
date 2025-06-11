#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0, cnt1 = 0;
    for(int i = 0; i < n - 2; i++)
    {
        if(s.substr(i, 3) == "LGR")
        {
            cnt++;
        }
        else if(s.substr(i, 3) == "CSP")
        {
            cnt1++;
        }
    }
    cout << min((cnt + 1) / 2, (cnt1 + 1) / 2) << endl;
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