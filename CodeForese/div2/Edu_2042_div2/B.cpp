#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n), f(n);
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i]--;
        f[c[i]]++;
    }
    int ans = count(f.begin(), f.end(), 1);
    //可以用这种方法避免奇数判断
    ans = (ans + 1) / 2 * 2;
    for(int i = 0; i < n; i++)
    {
        ans += (f[i] >= 2);
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
}