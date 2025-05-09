// https://acm.hdu.edu.cn/showproblem.php?pid=1213
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// struct DSU {
//     vector<int> p, r;
//     DSU(int n): p(n+1), r(n+1,0) {
//         iota(p.begin(), p.end(), 0);
//     }
//     int find(int x) {
//         return p[x]==x ? x : p[x] = find(p[x]);
//     }
//     void unite(int a, int b) {
//         a = find(a);
//         b = find(b);
//         if (a==b) return;
//         if (r[a]<r[b]) swap(a,b);
//         p[b] = a;
//         if (r[a]==r[b]) r[a]++;
//     }
// };
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // if (!(cin >> T)) return 0;
    // while (T--) {
    //     int N, M;
    //     cin >> N >> M;
    //     DSU dsu(N);
    //     for (int i = 0; i < M; i++) {
    //         int A, B;
    //         cin >> A >> B;
    //         dsu.unite(A, B);
    //     }
    //     // 统计不同的根
    //     unordered_set<int> roots;
    //     roots.reserve(N);
    //     for (int i = 1; i <= N; i++) {
    //         roots.insert(dsu.find(i));
    //     }
    //     cout << roots.size() << "\n";
    // }
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        DSU dsu(n);
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            dsu.merge(a, b);
        }
        set<int> se;
        for(int i = 0; i < n; i++)
        {
            se.insert(dsu.find(i));
        }
        cout << se.size() << endl;
    }
    return 0;
}
