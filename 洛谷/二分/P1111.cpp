#include <bits/stdc++.h>
using namespace std;
struct mst{
    int x, y, t;
};
bool cmp(mst a, mst b)
{
    return a.t < b.t;
}
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
int main()
{
    // int n, m;
    // cin >> n >> m;
    // vector<mst> a(m);
    // vector<int> f(n+1);
    // for(int i = 0; i < m; i++)
    // {
    //     cin >> a[i].x >> a[i].y >> a[i].t;
    // }
    // sort(a.begin(), a.end(), cmp);
    // for(int i = 1; i <= n; i++)
    // {
    //     f[i] = i;
    // }
    // auto find = [&](auto&& self, int x) -> int{
    //     return f[x] == x ? x : (f[x] = self(self ,f[x]));
    // };
    // for(int i = 0; i < m; i++)
    // {
    //     int fx = find(find, a[i].x);
    //     int fy = find(find, a[i].y);
    //     if(fx != fy)
    //     {
    //         f[fx] = fy;
    //         n--;
    //     }
    //     if(n == 1)
    //     {
    //         cout << a[i].t << "\n";
    //         return 0;
    //     }
    // }
    // cout << "-1\n";
    int n, m;
    cin >> n >> m;
    vector<mst> edg(m);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edg[i].x = a;
        edg[i].y = b;
        edg[i].t = c;
    }
    sort(edg.begin(), edg.end(), cmp);
    DSU dsu(n);
    for(int i = 0; i < m; i++)
    {
        int fx = dsu.find(edg[i].x);
        int fy = dsu.find(edg[i].y);
        if(fx != fy)
        {
            dsu.merge(edg[i].x, edg[i].y);
        }
        if(dsu.size(0) == n)
        {
            cout << edg[i].t << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}