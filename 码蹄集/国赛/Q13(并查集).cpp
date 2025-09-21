//https://www.matiji.net/exam/brushquestion/52/4693/305EE97B0D5E361DE6A28CD18C929AF0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//普通并查集
struct DSU
{
    std::vector<int> p, siz;
    DSU() {}
    DSU(int n) { init(n); }
    //初始化，把每个节点的根元素设置为自己，每个集合大小为1
    void init(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        siz.assign(n, 1);
    }
    //查找对应元素所属的根节点
    int find(int x)
    {
        while (x != p[x])
            x = p[x] = p[p[x]];
        return x;
    }
    //判断两个元素是否在同一集合
    bool same(int x, int y) { return find(x) == find(y); }
    // 合并两个元素所属的集合
    // 如果在同一集合则返回false, 否则进行合并并返回true
    bool merge(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        siz[px] += siz[py];
        p[py] = px;
        return true;
    }
    //返回元素所属集合的大小
    int size(int x) { return siz[find(x)]; }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        x--;
        y--;
        if(opt == 1)
        {
            dsu.merge(x, y);
        }
        else
        {
            if(dsu.same(x, y))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
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