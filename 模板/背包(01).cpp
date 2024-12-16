#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    //n为物品数量
    //m为背包容量
    cin >> n >> m;
    vector<int> w(n+1);
    vector<int> d(n+1);
    vector<int> f(m+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> d[i]; //读入数据
        //w[i]为第i个物品的重量
        //d[i]为第i个物品的价值
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= w[i]; j--)
        {
            if(f[j - w[i]] + d[i] > f[j])
            {
                f[j] = f[j - w[i]] + d[i]; // 状态转移方程
            }
        }
    }
    cout << f[m] << "\n";
    return 0;
}