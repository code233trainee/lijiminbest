#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char g[N][N];
bool vis[N][N];
int n, m, q, ans;
void dfs(int x, int y)
{
    vis[x][y] = true;
    ans++;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && g[nx][ny] != '#' && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    while(!q.empty())
    {
        ans++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && g[nx][ny] != '#' && !vis[nx][ny])
            {
                q.push({nx, ny});

                vis[nx][ny] = true;
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    // dfs(0, 0);
    bfs(0, 0);
    int ex = (n + m) * 2 + 4;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        bool flag = false;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(vis[nx][ny])
            {
                flag = true;
                break;
            }
        }
        g[x][y] = '.';
        if(flag && !vis[x][y])
        {
            // dfs(x, y);
            bfs(x, y);
        }
        cout << ans - ex << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}