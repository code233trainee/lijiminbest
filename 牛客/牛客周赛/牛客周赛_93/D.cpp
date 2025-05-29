#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    //优先队列，大的元素在前
    priority_queue<pair<ll, ll>> pq;
    vector<bool> vis(n+1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i > 1)
        {
            pq.emplace(a[i], i);
        }
    }
    while(k--)
    {
        auto [mx, indx] = pq.top();
        pq.pop();
        a[1] += mx;
        vis[indx] = true;
    }
    for(ll i = 1; i <= n; i++)
    {
        if(vis[i])
        {
            continue;
        }
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}