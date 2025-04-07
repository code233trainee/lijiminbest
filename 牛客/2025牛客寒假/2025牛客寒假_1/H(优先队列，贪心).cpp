#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct ty{
    int l, r, id;
};
bool cmp(ty a1, ty a2)
{
    if(a1.l != a2.l)
    {
        return a1.l < a2.l;
    }
    return a1.r < a2.r;
}
// 自定义比较函数对象
struct Compare {
    bool operator()(const ty& a, const ty& b) {
        if (a.r != b.r) {
            return a.r > b.r; // r 小的优先级高
        }
        return a.l < b.l; // r 相同，l 大的优先级高
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //相似题目：https://ac.nowcoder.com/acm/problem/20154 (建筑抢修)(反悔贪心)
    int n;
    cin >> n;
    vector<ty> a;
    for(int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r, i});
    }
    sort(a.begin(), a.end(), cmp);
    priority_queue<ty, vector<ty>, Compare> pq;
    vector<int> ans(n+1);
    int j = 0;
    for(int i = 1; i <= n; i++)
    {
        for(; j < n; j++)
        {
            if(i >= a[j].l)
            {
                pq.push(a[j]);
            }
            else
            {
                break;
            }
        }
        if(!pq.empty() && pq.top().l <= i && pq.top().r >= i)
        {
            ans[pq.top().id] = i;
            pq.pop();
        }
        else
        {
            continue;
        }
    }
    if(!pq.empty())
    {
        cout << "-1\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}