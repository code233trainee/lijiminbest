#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<int> x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    const int inf = int(1e9) + 20;
    int low = 0, high = inf;
    while(low + 1 < high)
    {
        int mid = (low + high) >> 1;//相当于除以二
        vector<pair<int, int>> e;
        for(int i = 0; i < n; i++)
        {
            int power = (h[i] + mid - 1) / mid;
            if(power <= m)
            {
                int from = x[i] - (m - power);
                int to = x[i] + (m - power);
                // e.emplace_back(from, +1); // 直接构造 pair 并插入
                // // 等价于：
                // e.push_back(std::make_pair(from, +1)); // 创建临时对象后插
                e.emplace_back(from, +1);
                e.emplace_back(to + 1, -1);
            }
        }
        // 默认按第一元素升序排序，若第一元素相同则按第二元素升序排序
        sort(e.begin(), e.end());
        bool good = false;
        int bal = 0;
        for(auto &[_, v] : e)
        {
            bal += v;
            if(bal >= k)
            {
                good = true;
                break;
            }
        }
        if(good)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << (high == inf ? -1 : high) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}