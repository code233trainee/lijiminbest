#include <bits/stdc++.h>
using namespace std;
int a[1010], l[1010], r[1010], n, ts ,ans;
int t[1010][1010];
int main()
{
    cin >> n >> ts;
    for(int i = 1; i <= ts; i++)
    {
        int x, y;
        cin >> x >> y;
        t[x][y] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            l[j] = r[j] = j;
        }
        for(int j = 1; j <= n; j++)
        {
            if(t[i][j] == 1)
            {
                a[j] = 0;
            }
            else
            {
                a[j]++;
            }
        }
        for(int j = 1; j <= n; j++)
        {
            while(l[j] != 1&& a[l[j] - 1] >= a[j])
            {
                l[j] = l[l[j] - 1];
            }
        }
        for(int j = n; j >= 1; j--)
        {
            while(r[j] != n && a[r[j] + 1] >= a[j])
            {
                r[j] = r[r[j] + 1];
            }
        }
        for(int j = 1; j <= n; j++)
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