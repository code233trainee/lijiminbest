#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<string> a(600);
int vis[600][600], num[600][600];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans = INT_MAX;
int sum = 0;
int id = 0;
void dfs(int x, int y, int id)
{
    vis[x][y] = 1;
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
            if(a[nx][ny] == '1')
            {
                dfs(nx, ny, id);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
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
                dfs(i, j, id);
                ans = min(ans, sum);
            }
        }
    }
    cout << ans;
    return 0;
}
