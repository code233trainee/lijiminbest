// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> a(n+1, vector<int>(m+1));
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     vector<vector<int>> cnt(n+1, vector<int>(m + 1));

//     for(int i = 1; i <= n; i++)
//     {
//         set<int> se;
//         int j = 1;
//         if(n > m)
//         {
//             for(j = 1; j <= m; j++)
//             {
//                 se.insert(a[i][j]);
//                 se.insert(a[j][i]);
//             }
//             cnt[i][j] = se.size();
//         }
//         else
//         {

//         }
//     }
//     set<int> se;
//     vector<vector<int>> ans(n+1, vector<int>(m+1));
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             ans[i][j] = ans[i-1][j-1] + cnt[i][j];
//         }
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= m; j++)
//         {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1007;
int n, m, g[N][N], sub[N][N], ans[N][N];
vector<pair<int, int>> pos[N * N]; //记录每个值的位置

//离散化函数
void discretize()
{
    vector<int> values;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            values.push_back(g[i][j]);
        }
    }
    //排序并去重
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    //建立映射关系
    map<int, int> ma;
    for(int i = 1; i <= values.size(); i++)
    {
        ma[values[i-1]] = i;//映射到1，2，3，....
    }
    // 将矩阵中的值替换为离散化后的值
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            g[i][j] = ma[g[i][j]];
        }
    }
}
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    discretize();

    //记录每个值在每一行第一次出现的位置
    for(int i = 1; i <= n; i++)
    {
        map<int, bool> vis;
        for(int j = 1; j <= m; j++)
        {
            if(vis[g[i][j]])
            {
                continue;
            }
            vis[g[i][j]] = true;
            pos[g[i][j]].push_back({i, j});
        }
    }

    //对每个值进行差分更新
    for(int val = 1; val <= n * m; val++)
    {
        if(!pos[val].empty())
        {
            int min_col = m + 1;//记录当前值的最小列
            for(auto p : pos[val])
            {
                int row = p.first;
                int col = p.second;
                if(col < min_col)
                {
                    sub[row][col]++;    //差分数组的起点;
                    sub[row][min_col]--;//差分数组的终点;
                }
                min_col = min(min_col, col);//更新最小列
            }
        }
    }
    //差分逆运算
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ans[i][j] = sub[i][j] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
        }
    }
    //输出
    for(int i = 1; i <= n; i++, cout << endl)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << ans[i][j] << " ";
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