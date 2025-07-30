#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int m, n;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            if(i == 1)
            {
                if(j == 1)
                {
                    a[i][j] = x;
                }
                else
                {
                    a[i][j] = x + a[i][j-1];
                }
            }
            else
            {
                if(j == 1)
                {
                    a[i][j] = x + a[i-1][j];
                }
                else
                {
                    a[i][j] = x + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << a[i][j] / (i * j) << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}