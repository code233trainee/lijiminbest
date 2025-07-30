#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> vis(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = inf;
    for(int i = 1; i <= n - 1; i++)
    {
        int l = a[i+1];
        int r = a[i+1];
        for(int j = i+1; j <= n; j++)
        {
            l = min(l, a[j]);
            r = max(r, a[j]);
            if(a[i] >= l - 1 && a[i] <= r + 1)
            {
                ans = min(ans,  j - i - 1);
            }
        }
    }
    for(int i = n; i >= 2; i--)
    {
        int l = a[i-1];
        int r = a[i-1];
        for(int j = i - 1; j >= 1; j--)
        {
            l = min(l, a[j]);
            r = max(r, a[j]);
            if(a[i] >= l - 1 && a[i] <= r + 1)
            {
                ans = min(ans, i - j - 1);
            }
        }
    }
    if(ans == inf)
    {
        ans = -1;
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