#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<int> x(m), v(m);
    for(int i = 0; i < m; i++)
    {
        cin >> x[i] >> v[i];
    }
    multiset<int> s;//允许重复元素，并且默认重小到大排序
    int ptr = 0;
    int k = 1;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        while(ptr < m && x[ptr] < l[i])
        {
            s.insert(v[ptr++]);////每次遇到能量就加入
        }
        while(k <= r[i] - l[i] + 1)
        {
            if(s.empty())
            {
                ans = -1;
                break;
            }
            //每次只选择最大的能量
            k += *prev(s.end());//解引用最后一个元素(最大的能量)
            s.erase(prev(s.end()));//prev(迭代器，向前移动的位数(默认是1))函数返回的是一个新的迭代器
            ans += 1;
        }
        if(ans == -1)
        {
            break;
        }
    }
    cout << ans << "\n";
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
}