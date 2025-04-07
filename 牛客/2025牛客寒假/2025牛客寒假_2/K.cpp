#include <bits/stdc++.h>
using namespace std;
int vis[505][505];
int flag[505][505];
int n, m, targ = 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void dfs(int x, int y, int id, vector<string> &a)
{
    flag[x][y] = id;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == '1')
        {
            dfs(nx, ny, id, a);
        }
    }
}
int main()
{
    cin >> n >> m;
    int id = 0;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vs[i][j] == '1' && vis[i][j] == 0)
            {
                ++id;
                dfs(i, j, id, vs);
            }
        }
    }
    vector<int> g(m * n + 1);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (vs[i][j] == '0') 
            {
                map<int, bool> ex;
                for (int k = 0; k < 4; k++) 
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && vs[nx][ny] == '1' && !ex[flag[nx][ny]]) 
                    {
                        g[flag[nx][ny]]++;
                        ex[flag[nx][ny]] = true;
                    }
                }
            }
        }
    }
    sort(g.begin() + 1, g.begin() + id + 1);
    cout << g[1];
    return 0;
}