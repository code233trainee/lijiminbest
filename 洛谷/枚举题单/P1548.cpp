#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int z = 0;
    int c = 0;
    //直接枚举点
    //方块左上和右下的点
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = i+1; k <= m; k++)
            {
                for(int p = j+1; p <= n; p++)
                {
                    if(k-i == p-j)
                    {
                        z++;
                    }
                    else
                    {
                        c++;
                    }
                }
            }
        }
    }
    cout << z << " " << c;
    return 0;
}