#include <bits/stdc++.h>
using namespace std;
int a[1010], l[1010], r[1010], n, m, ans;
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
            if(c == 'R')
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
            ans = max(ans, (r[j] - l[j] + 1) * a[j]);
        }
    }
    cout << ans*3 << "\n";
    return 0;
}