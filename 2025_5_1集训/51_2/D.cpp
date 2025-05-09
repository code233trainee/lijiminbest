// https://codeforces.com/problemset/problem/1682/C
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> ma;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ma[x]++;
    }
    int cnt1 = 0, cnt2 = 0;
    for(auto &[x, y] : ma)
    {
        if(y > 1)
        {
            cnt2++;
        }
        if(y == 1)
        {
            cnt1++;
        }
    }
    cout << cnt2 + (cnt1 + 1) / 2 << "\n";
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