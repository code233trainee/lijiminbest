#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct st{
    ll l, r;
};
bool cmp(st a1, st a2)
{
    return a1.l < a2.l; 
}
bool cmp2(st a1, st a2)
{
    return a1.r > a2.r; 
}
int main()
{
    //流水调度问题，Johnson算法
    //对所有a<=b的任务按a升序排序 对所有a>b的任务按b降序排序 然后两者组合就是最优的执行顺序 然后模拟一遍计算时间
    //本质上是尽量减少b的等待时间
    int n;
    cin >> n;
    vector<st> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].l;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].r;
    }
    vector<st> front, back;
    for(int i = 0; i < n; i++)
    {
        if(a[i].l <= a[i].r)
        {
            front.push_back(a[i]);
        }
        else
        {
            back.push_back(a[i]);
        }
    }
    sort(front.begin(), front.end(), cmp);
    sort(back.begin(), back.end(), cmp2);
    vector<st> order;
    for(auto z : front)
    {
        order.push_back(z);
    }
    for(auto z : back)
    {
        order.push_back(z);
    }
    int endA = 0, endB = 0;
    for (auto &job : order) {
        endA += job.l;
        endB = max(endA, endB) + job.r;
    }
    cout << endB;
    return 0;
}