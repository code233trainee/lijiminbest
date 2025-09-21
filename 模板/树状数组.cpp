#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 树状数组模板
class BIT{
public:
    BIT(int size) : size_(size), tree_(size + 1, 0) {}

    //单点更新
    void update(int index, int delta)
    {
        // lowbit: i & -i
        for(int i = index + 1; i <= size_; i+=(i & -i))
        {
            tree_[i] += delta;
        }
    }

    //单点查询(前缀和)
    int query(int index)
    {
        int sum = 0;
        for(int i = index + 1; i > 0; i -= (i & -i))
        {
            sum += tree_[i];
        }
        return sum;
    }

    //区间查询
    int queryRange(int left, int right)
    {
        return query(right) - query(left - 1);
    }
private:
    int size_;
    vector<int> tree_;
};

void solve()
{
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}