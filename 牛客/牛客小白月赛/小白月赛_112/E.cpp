#include <bits/stdc++.h>
using namespace std;
int pre[10005][10005], a[105];
bool dp[105][105];
void query(int q)
{
    for(int i = 1; i <= ceil(sqrt(q)); i++)
    {
        //遍历因子
        if(q % i != 0)
        {
            continue;
        }
        //因数分解
        if(dp[i][q/i])
        {
            vector<int> vx, vy;
            int x = i;
            int y = q / i;
            while(x != 0 || y != 0)
            {
                if(pre[x][y] > 0)
                {
                    vx.push_back(pre[x][y]);
                    x -= pre[x][y];
                }
                else
                {
                    vy.push_back(pre[x][y] * (-1));
                    y += pre[x][y];
                }
            }
            cout << "Yes\n";
            cout << vx.size() << " " << vy.size() << "\n";
            for(int j = 0; j < vx.size(); j++)
            {
                cout << vx[j] << " ";
            }
            cout << "\n";
            for(int j = 0; j < vy.size(); j++)
            {
                cout << vy[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "No\n";
}
int main()
{
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int x = 100; x >= 0; x--)
        {
            for(int y = 100; y >= 0; y--)
            {
                if(dp[x][y])
                {
                    continue;
                }
                if(x >= a[i] && dp[x-a[i]][y])
                {
                    dp[x][y] = 1;
                    pre[x][y] = a[i];
                }
                else if(y >= a[i] && dp[x][y-a[i]])
                {
                    dp[x][y] = 1;
                    pre[x][y] = a[i] * (-1);
                }
            }
        }
    }
    while(m--)
    {
        int q;
        cin >> q;
        query(q);
    }
    return 0;
}