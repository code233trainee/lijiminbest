#include <bits/stdc++.h>
using namespace std;

static const int MAXA = 5000;
static const int INF  = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 1) 先算全数组的 G = gcd(a[0],a[1],...,a[n-1])
        int G = a[0];
        for (int i = 1; i < n; i++) {
            G = std::gcd(G, a[i]);
        }

        // 2) 统计有多少个元素已经恰好等于 G
        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == G) cnt0++;
        }
        // 如果已有至少一个 G，就可以直接“一对一”把其他都转成 G
        if (cnt0 > 0) {
            // 剩下 n - cnt0 个元素，每个元素各做一次 gcd(x, G) → G
            cout << (n - cnt0) << "\n";
            continue;
        }

        // 3) cnt0 == 0：说明数组里没有 G，我们必须先“造”出第一个 G
        //    所以需要先求 f* = 在一系列 gcd 操作后出现第一个 G 的最小步数
        //    再加上 (n-1) 把剩余 n-1 个元素转成 G。

        // 去重出原数组中所有不同的数，供 BFS 使用
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        // 现在 a[i] (i=0..a.size()-1) 就是所有不重复的原始值

        // BFS 状态是“当前值 v”，我们想知道从这些源头（每个 a[i]）到达 G 最少要几步
        static int dist[MAXA + 1];
        for (int v = 1; v <= MAXA; v++) {
            dist[v] = INF;
        }

        queue<int> que;
        // 多源入队：每个原始值 a[i] 都令 dist[a[i]] = 0
        for (int v : a) {
            dist[v] = 0;
            que.push(v);
        }

        // 标记是否已经把 G 的最短距离算出来
        int fstar = -1;

        while (!que.empty()) {
            int v = que.front(); 
            que.pop();
            int d = dist[v];
            if (v == G) {
                // 一旦队列弹出 G，说明我们已经找到 dist[G] 的最小值
                fstar = d;
                break;
            }
            // 从 v 可以跳到 gcd(v, x) （x 取自所有原始不同的 a[]）
            // 注意：a 中是已去重的
            for (int x : a) {
                int u = std::gcd(v, x);
                if (dist[u] > d + 1) {
                    dist[u] = d + 1;
                    que.push(u);
                }
            }
        }

        // BFS 结束后，dist[G] 就存着最少操作步数 f*
        // 理论上 fstar 一定被赋值；若万一没被赋值，可直接设为 dist[G]
        // if (fstar < 0) {
        //     fstar = dist[G];
        // }

        // 最终答案 = f*（造出第一个 G） + (n - 1)（把其余 n-1 个都变 G）
        int ans = fstar + ( (int)a.size() == n ? n-1 : n-1 ); 
        // 注意：这里 a.size() == n 只是检查去重后大小与 n 是否相等，不影响计数
        // 事实上后项永远是 n-1，因为最初 cnt0==0 时，所有 n 个位置都不是 G。

        cout << ans << "\n";
    }

    return 0;
}
