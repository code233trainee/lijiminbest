#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> vv(n+1, vector<int>(n+1));
    int x, y;
    double ans = 0;
    for(double i = 1; i <= m; i++)
    {
        cin >> x >> y;
        vv[x][y] = 1;
        for(double j = 1; j <= n; j++)
        {
            for(double k = 1; k <= n; k++)
            {
                double dis = sqrt((pow(x - j, 2)) + pow(y - k, 2));
                if(dis <= r)
                {
                    vv[j][k] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(vv[i][j] == 1)
            {
                ans++;
            }
        }   
    }
    cout << ans << endl;
    return 0;
}