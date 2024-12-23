#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N];
int n, m;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
void bfs(int i, int j)
{
    int cnt = 0;
    for(int k = 0; k < 8; k++)
    {
        int aa = i + dx[k];
        int bb = j + dy[k];
        if(aa < 1 || aa > n || bb < 1 || bb > m)
        {
            continue;
        }
        if(a[aa][bb] == 9)
        {
            cnt++;
        }
    }
    a[i][j] = cnt;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int temp;
            cin >> temp;
            if(temp)
            {
                a[i][j] = 9;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " \n"[j == m];
        }
    }
    return 0;
}