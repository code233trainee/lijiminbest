#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1, l = n, r = j; j < n; j++)
        {
            l = max(l, j + 1);
            while(l > j + 1 && a[i] + a[j] + a[l - 1] > a[n-1])
            {
                l--;
            }
            r = max(r, j + 1);
            while(r < n && a[r] < a[i] + a[j])
            {
                r++;
            }
            ans += max(r - l, 0);
        }
    }

    // for(int k = 3; k <= n; k++)
    // {
    //     for(int j = 2; j <= k; j++)
    //     {
    //         int lim = max(a[n] - a[j] - a[k], a[k] - a[j]);
    //         int pos = (int)(upper_bound(a.begin() + 1, a.begin() + j, lim) - a.begin());
    //         ans += j - pos;
    //     }
    // }
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