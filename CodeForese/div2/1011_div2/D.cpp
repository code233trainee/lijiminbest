#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    priority_queue<ll> pq;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        pq.push(a[i]);
        //最后的k个盘子是一定选不到的，需要的分钟数大于了n
        if((n - i) % (k + 1) == 0)
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}