#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;

    bool f = 0;
    if(n > m)
    {
        swap(n, m);
        f = 1;
    }

    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++)
    {
        g[i][i] = i;
    }
    for(int j = n + 1; j < m; j++)
    {
        g[n][j] = j;
    }

    int s = m;
    for(int i = 1; i < n; i++)
    {
        g[i][m] = (m + i) ^ i;
        s ^= g[i][m];
    }
    g[n][m] = s;

    int xor_sum = 0;
    for(int j = 1; j <= m; j++)
    {
        xor_sum ^= g[n][j];
    }

    if(xor_sum != n + m)
    {
        cout << -1 << endl;
    }
    else
    {
        if(f == 0)
        {
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    cout << g[i][j] << " \n"[j == m]; 
                }
            }
        }
        else
        {
            for(int j = 1; j <= m; j++)
            {
                for(int i = 1; i <= n; i++)
                {
                    cout << g[i][j] << " \n"[i == n];
                }
            }
        }
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