#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1010];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int now = n;
    ll ans = -1e18;
    for(int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for(int i = 1; i <= now; i++)
        {
            sum = sum + a[i];
        }
        if(i == 1)
        {
            ans = max(ans, sum);
        }
        else
        {
            ans = max(ans, max(sum, (-sum)));
        }
        for(int i = 1; i < now; i++)
        {
            a[i] = (a[i+1] - a[i]);
        }
        now--;
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