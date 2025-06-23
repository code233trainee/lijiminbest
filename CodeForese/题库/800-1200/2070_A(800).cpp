// https://codeforces.com/problemset/problem/2070/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int ans = (n / 15) * 3;
    n %= 15;
    for(int i = 0; i <= n; i++)
    {
        if(i % 3 == i % 5)
        {
            ans++;
        }
    }
    cout << ans << "\n";
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