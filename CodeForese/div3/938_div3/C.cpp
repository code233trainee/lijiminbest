#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    //双端队列
    deque<ll> dq(n);
    for(int i = 0; i < n; i++)
    {
        cin >> dq[i];
    }
    //限定队列中的元素大于1
    while(dq.size() > 1 && k)
    {
        //每次确定要击毁至少一艘船
        ll mn = min(dq.front(), dq.back());
        if(k < 2*mn)
        {
            dq.front() -= k / 2 + k % 2;
            dq.back() -= k / 2;
            k = 0;
        }
        else
        {
            dq.front() -= mn;
            dq.back() -= mn;
            k -= 2 * mn;
        }
        if(dq.front() == 0)
        {
            dq.pop_front();
        }
        if(dq.back() == 0)
        {
            dq.pop_back();
        }
    }
    int ans = n - dq.size();
    cout << ans + (dq.size() && dq.front() <= k) << '\n';
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
