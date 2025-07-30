// https://codeforces.com/problemset/problem/2061/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int cnteven = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x % 2 == 0)
        {
            cnteven++;
        }
    }
    int cntodd = n - cnteven;
    int ans = 0;
    if(cnteven >= 1)
    {
        ans = 1 + cntodd;
    }
    else
    {
        ans = cntodd - 1;
    }
    cout << ans << endl;
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