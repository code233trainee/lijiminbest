#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSUV
{
    std::vector<int> p, siz, d;
    DSUV() {}
    DSUV(int n) { init(n); }
    void init(int n)
    {
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        siz.assign(n, 1);
        d.assign(n, 0);
    }
    int find(int x)
    {
        if (p[x] != x)
        {
            int u = find(p[x]);
            d[x] += d[p[x]]; // 按情况修改
            p[x] = u;
        }
        return p[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y, int s)
    {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        siz[px] += siz[py];
        p[py] = px;
        d[py] = (d[x] - d[y] + s); // s为偏移量，按情况修改
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

const int N = 2e5 + 5;
int n, m, fa[N];
struct Edge{
    int u, v, w;
}e[N];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    fa[x] = y;
}
bool check(int X)
{
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for(int i = 1; i <= m; i++)
    {
        if((e[i].w | X) == X)
        {
            merge(e[i].u, e[i].v);
        }
    }
    return find(1) == find(n);
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int ans = 0;
    for(int i = 30; i >= 0; i--)
    {
        if(!check(ans | ((1 << i) - 1)))
        {
            ans |= (1 << i);
        }
    }
    cout << ans << endl;
    return 0;
}