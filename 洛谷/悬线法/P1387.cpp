//悬线法
#include <bits/stdc++.h>
using namespace std;
int a[110], l[110], r[110], n, m, ans;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            l[j] = r[j] = j;
        }
        for(int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if(c == '0')
            {
                a[j] = 0;
            }
            else
            {
                a[j]++;
            }
        }
        for(int j = 1; j <= m; j++)
        {
            while(l[j] != 1 && a[l[j] - 1] >= a[j])
            {
                l[j] = l[l[j] - 1];
            }
        }
        for(int j = m; j >= 1; j--)
        {
            while(r[j] != m && a[r[j] + 1] >= a[j])
            {
                r[j] = r[r[j] + 1];
            }
        }
        for(int j = 1; j <= m; j++)
        {
            if((r[j] - l[j] + 1) >= a[j])
            {
                ans = max(ans, a[j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
