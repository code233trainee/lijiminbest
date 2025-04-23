#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll T, n;
    // 默认的是优先级高 元素值大
    // 优先级高的元素值小
    // 多个元素，应该是以元素顺序为主
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    ll x = 1, y = 1, dis = 2; //位置和步数
    cin >> n;
    vector<pair<ll, ll>> ans(n+1);
    for(ll i = 1, xx; i <= n; i++)
    {
        cin >> xx;
        if(xx && pq.size() &&  get<0>(pq.top()) < dis)
        {
            auto p = pq.top();
            pq.pop();
            ans[i] = {get<1>(p), get<2>(p)};
        }
        else
        {
            ans[i] = {x, y};
            pq.push({x+y+1, x+1, y});
            pq.push({x+y+1, x, y+1});
            pq.push({x+y+4, x+1, y+1});

            if(y - 1 == 0)
            {
                swap(x, y);
                y += 3;
            }
            else
            {
                x += 3;
                y -= 3;
            }
            dis = x + y;
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
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