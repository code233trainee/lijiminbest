#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const char mp[] = "<>^v";

int n, m, f[maxn][maxn];
char g[maxn][maxn];
int main()
{
    cin >> n >> m;
    memset(f, -1, sizeof(f));
    queue<pair<int, int>> q;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
        for(int j = 0; j < m; j++)
        {
            if(vs[i][j] == 'E')
            {
                f[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1 || vs[nx][ny] == '#')
            {
                continue;
            }
            if(f[nx][ny] == -1)
            {
                f[nx][ny] = f[x][y]+1;
                g[nx][ny] = mp[i];
                q.push({nx,ny});
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << (vs[i][j] == '.' ? g[i][j] : vs[i][j]);
        }
        cout << endl;
    }
    
    return 0;
}