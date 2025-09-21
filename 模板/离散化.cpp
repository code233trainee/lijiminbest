#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1007;
int n, m;
int g[N][N];
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
        ma[values[i-1]] = 1;//映射到1，2，3，....
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