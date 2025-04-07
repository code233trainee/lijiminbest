#include <bits/stdc++.h>
using namespace std;
// 编号 = x*m + y
int n, m, ans = INT_MAX, sum, id;
vector<string> a(600);
int vis[600][600], num[600][600];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<int> q;
void bfs(int x, int y)
{
    vis[x][y] = 1;
    while(!q.empty())
    {
        q.pop();
    }
    q.push(x*m+y);
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        int x = t / m;
        int y = t % m;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            {
                if(a[nx][ny] == '0' && num[nx][ny] != id)
                {
                    sum++;
                    num[nx][ny] = id;

                }
                if(a[nx][ny] == '0') continue;
                vis[nx][ny] = 1;
                q.push(nx*m+ny);
            }
        }
    }
    
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '1' && !vis[i][j])
            {
                id++;
                sum = 0;
                bfs(i, j);
                ans = min(ans, sum);
            }
        }
    }
    cout << ans;
    return 0;
}