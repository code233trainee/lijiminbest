#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[50010], pre[50010], suf[50010];
void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    int l = 0;
    int ans = 0;
    for(int r = 0; r < n; r++)
    {
        while(l < r && a[r] - a[l] > k)
        {
            l++;
        }
        pre[r] = max(pre[r - 1], r - l + 1);
    }
    int r = 0;
    for(int l = 0; l < n; l++)
    {
        while(r < n && a[r] - a[l] <= k)
        {
            r++;
        }
        suf[l] = max(suf[l], r - l);
    }
    for(int i = 0; i < n-1; i++)
    {
        ans = max(ans, pre[i] + suf[i+1]);
    }
    cout << ans << endl;
}
int main()
{
    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}