#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int n, m, k;
int dir[110000], x, y;
bool s[55][55][2010] = {false};
char ma[110][110];
void dfs(int stp, int xx, int yy, bool flag)
{
    if(xx < 1 || yy < 1 || xx > n || yy > m || stp > k || s[xx][yy][stp] || ma[xx][yy] == 'X')
    {
        return;
    }
    if(stp == k)
    {
        ma[xx][yy] = '*';
    }
    dfs(stp, xx + dx[dir[stp]], yy + dy[dir[stp]], true);
    if(flag)
    {
        dfs(stp + 1, xx + dx[dir[stp + 1]], yy + dy[dir[stp + 1]], true);
    }
    s[xx][yy][stp] = true;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> ma[i][j];
            if(ma[i][j] == '*')
            {
                x = i;
                y = j;
                ma[i][j] = '.';
            }
        }
    }
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        string str;
        cin >> str;
        switch(str[0])
        {
            case 'N' : dir[i] = 1; break;
            case 'S' : dir[i] = 2; break;
            case 'W' : dir[i] = 3; break;
            default : dir[i] = 4;
        }
    }
    dfs(1, x, y, false);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << ma[i][j];
        }
        cout << endl;
    }
    return 0;
}