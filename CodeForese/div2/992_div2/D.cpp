#include <bits/stdc++.h>
void solve()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> a(n);
    //差值为偶数且不等于2，就保证了|ai - ai+1|不是素数
    int cur = 1;
    //传进来的x是当前节点，p是父亲节点
    auto dfs = [&](auto &&self, int x, int p = -1) -> void {
        a[x] = cur;
        bool first = true;
        //节点的儿子们
        for(auto y : adj[x])
        {
            if(y == p)
            {
                continue;
            }
            if(first)
            {
                first = false;
                cur++;
                self(self, y, x);//往下深度遍历
                cur++;
            }
            else
            {
                cur += 2;
                self(self, y, x);
            }
        }
    };
    dfs(dfs, 0);
    //上述lambda表达式的C++20引入的新版本(主要体现在递归调用的不同)
    // auto dfs = [&](this auto &&self, int x, int p = -1) -> void {
    // a[x] = cur;
    // bool first = true;
    // for(auto y : adj[x])
    // {
    //     if(y == p)
    //     {
    //         continue;
    //     }
    //     if(first)
    //     {
    //         first = false;
    //         cur++;
    //         self(y, x);
    //         cur++;
    //     }
    //     else
    //     {
    //         cur += 2;
    //         self(y, x);
    //     }
    // }
    // };
    // dfs(0);
    for(int i = 0; i < n; i++)
    {
        std::cout << a[i] << " \n"[i == n-1];//i==n-1时输出\n,其他情况输出空格
    }
}
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}