#include <bits/stdc++.h>
using namespace std;
const int N = 207;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, sx, sy, ans = INT_MAX, vis2[N][N];
char ma[N][N];
vector<pair<int, int>> v;
struct st{
    int x, y;
    int t;
};

void bfs(int sx, int sy)
{
    int vis[N][N] = {0}, flag = 0;
    queue<st> q;
    q.push({sx, sy, 0});
    while(!q.empty())
    {
        st t = q.front();
        q.pop();
        if(ma[t.x][t.y] == 'P')
        {
            ans = min(t.t, ans);
            return;
        }
        if(vis[t.x][t.y])
        {
            continue;
        }
        vis[t.x][t.y] = 1;
        for(int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && ma[nx][ny] != '#')
            {
                if(ma[nx][ny] == '.' || ma[nx][ny] == 'P')
                {
                    q.push({nx, ny, t.t + 1});
                }
                if(ma[nx][ny] == '@' && !vis2[nx][ny] && !flag)
                {
                    flag = 1;
                    vis2[nx][ny] = 1;
                    for(auto p : v)
                    {
                        if(p.first == nx && p.second == ny)
                        {
                            continue;
                        }
                        q.push({p.first, p.second, t.t+1});
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> ma[i][j];
            if(ma[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if(ma[i][j] == '@')
            {
                v.push_back({i, j});
            }
        }
    }
    bfs(sx, sy);
    bfs(sx, sy);
    if(ans == INT_MAX)
    {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}