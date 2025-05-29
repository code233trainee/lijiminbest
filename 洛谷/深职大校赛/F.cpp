#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vv(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> vv[i][j];
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        if(vv[i][0] == 0 && !vis[i][0])
        {
            vis[i][0] = true;
            q.push({i, 0});
        }
        if(vv[i][m-1] == 0 && !vis[i][m-1])
        {
            vis[i][m-1] = true;
            q.push({i, m-1});
        }
    }
    for(int j = 0; j < m; j++)
    {
        if(vv[0][j] == 0 && !vis[0][j])
        {
            vis[0][j] = true;
            q.push({0, j});
        }
        if(vv[n-1][j] == 0 && !vis[n-1][j])
        {
            vis[n-1][j] = true;
            q.push({n-1, j});
        }
    }
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i]; 
            if(xx < 0 || xx >= n || yy < 0 || yy >= m)
            {
                continue;
            }
            if(!vis[xx][yy] && vv[xx][yy] == 0)
            {
                vis[xx][yy] = true;
                q.push({xx, yy});
            } 
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vv[i][j] == 0 && !vis[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}