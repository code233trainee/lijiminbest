// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> d(n);
//     for(int i = 0; i < n - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         d[u].push_back(v);
//         d[v].push_back(u);
//     }
//     vector<int> vis(n, 0);
//     vector<int> f(n);
//     vector<array<int, 2>> dep;
//     int v = -1;
//     array<int, 4> r1{};

//     auto dfs = [&](auto &self, int cur = 0, int fa = -1) -> void {
//         if(vis[cur] != v)
//         {
//             return;
//         }
//         vis[cur] = v+1;
//         f[cur] = fa;
//         dep[cur] = {1, cur};
//         cmax(r1, {1, cur, -1, cur});
//         array<int, 2> t1{}, t2{};
//         for(int x : d[cur])
//         {
//             if(x == fa || vis[x] != v)
//             {
//                 continue;
//             }
//             self(x, cur);
//             cmax(dep[cur], {dep[x][0] + 1, dep[x][1]});
//             cmax(r1, {dep[x][0] + 1, max(cur, dep[x][1]), min(cur, dep[x][1]), cur});
//             if(dep[x] > t1)
//             {
//                 t2 = t1;
//                 t1 = dep[x];
//             }
//             else if(dep[x] > t2)
//             {
//                 t2 = dep[x];
//             }
//         }
//         if(t1[0] && t2[0])
//         {
//             cmax(r1, {t1[0] + t2[0] + 1, max(t1[1], t2[1]), min(t1[1], t2[1]), cur});
//         }
//     };
//     vector<array<int, 3>> res;
//     int imp = n + n;
//     int gone = 0;
//     for(int i = 0; gone < n; i++)
//     {
//         v = i;
//         dep.assign(n, {});
//         for(int j = 0; j < n; j++)
//         {
//             if(vis[j] != v)
//             {
//                 continue;
//             }
//             r1 = {};
//             dfs(j);
//             if(r1[2] == -1)
//             {
//                 res.push_back({1, r1[1], r1[1]});
//                 vis[r1[1]] = imp;
//             }
//             else
//             {
//                 res.push_back({1, r1[1], r1[2]});
//                 int x = r1[1];
//                 while(x != r1[3])
//                 {
//                     vis[x] = imp;
//                     x = f[x];
//                 }
//                 x = r1[2];
//                 while(x != r1[3])
//                 {
//                     vis[x] = imp;
//                     x = f[x];
//                 }
//                 vis[r1[3]] = imp;
//             }
//         }
//         gone += r1[0];
//     }
//     sort(res.begin(), res.end(), [](auto x, auto y) {
//         return x > y;
//     });
//     for(auto [x, y, z] : res)
//     {
//         cout << x << " " << y + 1 << " " << z + 1 << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }