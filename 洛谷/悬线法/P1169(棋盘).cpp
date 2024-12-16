#include <bits/stdc++.h>
using namespace std;
int a[2010][2010], l[2010][2010], r[2010][2010], up[2010][2010] ,n, m, ans1, ans2;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            l[i][j] = r[i][j] = j;
            up[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++)//左边界
    {
        for(int j = 2; j <= m; j++)
        {
            if(a[i][j] != a[i][j-1])
            {
                l[i][j] = l[i][j-1];
            }
        }
    }
    for(int i = 1; i <= n; i++)//右边界
    {
        for(int j = m-1; j >= 1; j--)
        {
            if(a[i][j] != a[i][j+1])
            {
                r[i][j] = r[i][j+1];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i > 1 && a[i][j] != a[i-1][j])
            {
                l[i][j] = max(l[i][j], l[i-1][j]);
                r[i][j] = min(r[i][j], r[i-1][j]);
                up[i][j] = up[i-1][j] + 1;
            }
            int a = r[i][j] - l[i][j] + 1;
            int b = min(a, up[i][j]);
            ans1 = max(ans1, b*b);
            ans2 = max(ans2, a*up[i][j]);
        }
    }
    cout << ans1 << "\n";
    cout << ans2 << "\n";
    return 0;
}