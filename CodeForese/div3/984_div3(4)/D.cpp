#include <bits/stdc++.h>
using namespace std;

//数据量不是很大
char c[1005][1005];
char layer[4005];
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int count = 0;
    for(int i = 0; (i + 1) * 2 <= n && (i + 1) * 2 <= m; i++)
    {
        int pos = 0;
        //注意这里数组的处理
        for(int j = i; j < m - i; j++)
        {
            layer[pos++] = c[i][j];
        }
        for(int j = i + 1; j < n - i - 1; j++)
        {
            layer[pos++] = c[j][m - i - 1];
        }
        for(int j = m - i - 1; j >= i; j--)
        {
            layer[pos++] = c[n - i - 1][j];
        }
        for(int j = n - i - 2; j >= i + 1; j--)
        {
            layer[pos++] = c[j][i];
        }

        for(int j = 0; j < pos; j++)
        {
            if(layer[j % pos] == '1' && layer[(j + 1) % pos] == '5' && layer[(j + 2) % pos] == '4' && layer[(j + 3) % pos] == '3')
            {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}