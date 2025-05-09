#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[200005];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int sum = 0, ans = 0;
    for(int i = n; i >= 1; i--)
    {
        sum += cnt[i];
        if(sum >= m)
        {
            ans = max(cnt[i], ans);
        }
    }
    cout << min(ans, m) << endl;
    // map<int, int> ma;
    // for(int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     ma[x]++;
    // }
    // int ans = 0, sum = n;
    // for(auto [a, b] : ma)
    // {
    //     if(sum >= m)
    //     {
    //         ans = max(ans, min(b, m));
    //     }
    //     sum -= b;
    // }
    // cout << ans << endl;
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