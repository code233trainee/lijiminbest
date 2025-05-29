#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll h, w;
ll a[22][22];
bool vis[22][22];
ll sum, ans;
void dfs(int x, int y, ll xor_sum)
{
    if(x > h)
    {
        ans = max(ans, xor_sum);
        return;
    }

    int nx = x;
    int ny = y + 1;
    if(ny > w)
    {
        nx++;
        ny = 1;
    }
    //格子不参与运算
    if(vis[x][y])
    {
        dfs(nx, ny, xor_sum);
        return;
    }

    //格子参与运算
    vis[x][y] = true;
    dfs(nx, ny, xor_sum ^ a[x][y]);
    vis[x][y] = false;

    //横着盖
    if(y + 1 <= w && !vis[x][y+1])
    {
        vis[x][y] = true;
        vis[x][y+1] = true;
        dfs(nx, ny, xor_sum);
        vis[x][y] = false;
        vis[x][y+1] = false;
    }
    //竖着盖
    if(x + 1 <= h && !vis[x+1][y])
    {
        vis[x][y] = true;
        vis[x+1][y] = true;
        dfs(nx, ny, xor_sum);
        vis[x][y] = false;
        vis[x+1][y] = false;
    }
}
int main()
{
    cin >> h >> w;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
        } 
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}