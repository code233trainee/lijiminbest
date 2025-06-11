#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge{
    int u, v;
    int w;
    bool operator< (const Edge& e){
        return w < e.w;
    }
};
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
        //0-st
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
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<Edge> e;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            e.push_back({i-1, j-1, a[i][j]});
        }
    }
    sort(e.begin(), e.end());
    DSU dsu(n);
    ll ans = 0;
    for(int i = 0; i < e.size(); i++)
    {
        if(dsu.same(e[i].u-1, e[i].v-1))
        {
            continue;
        } 
        else
        {
            ans += e[i].w;
            dsu.merge(e[i].u-1, e[i].v-1);
        }
    }
    cout << ans << endl;
    return 0;
}