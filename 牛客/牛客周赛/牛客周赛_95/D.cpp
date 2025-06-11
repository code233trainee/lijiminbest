#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int q;
    cin >> q;
    set<pair<int, int>> s; 
    int mx = -1e8;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        //二分查找第一个严格大于r的元素
        auto it = s.upper_bound({r, INT_MAX});
        bool ok = true;
        //只要不是第一个元素
        if(it != s.begin())
        {
            --it;
            if(it->second >= l)
            {
                ok = false;
            }
        }
        if(ok)
        {
            s.insert({l, r});
            mx = max(mx, r - l + 1);
        }
        cout << mx + 1 << endl;
    }
    return 0;
}