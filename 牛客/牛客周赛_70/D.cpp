#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1), mx(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    if(n <= 2)
    {
        for(auto z : v)
        {
            ans += z;
        }
        cout << ans << "\n";
        return;
    }
    for(int i = n; i >= 1; i--)
    {
        //后缀求和，求最大值
        mx[i] = max(mx[i+1], v[i]);
    }
    ans = v[1] + v[n];
    for(int i = 1; i <= min(n - 1, k + 1); i++)
    {
        ans = max(ans, v[i] + mx[max(i + 1, n - (k - (i - 1)))]);
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