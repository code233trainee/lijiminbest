#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int x, y;
};
int n, m, aa, bb;
ll p, s[505][505], now;
bool flag[505][505];
priority_queue<node> q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

//值小的优先(默认是大的优先)
bool operator<(const node &A, const node &B)
{
    return s[A.x][A.y] > s[B.x][B.y];
}
int main()
{
    cin >> n >> m >> p >> aa >> bb;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
        }
    }
    now = s[aa][bb];
    flag[aa][bb] = 1;
    for(int i = 0; i < 4; i++)
    {
        int x2 = aa + dx[i];
        int y2 = bb + dy[i];
        if(x2 < 1 || x2 > n || y2 < 1 || y2 > m)
        {
            continue;
        }
        q.push({aa + dx[i], bb + dy[i]});
    }
    while(!q.empty())
    {
        node t = q.top();
        q.pop();
        if(s[t.x][t.y] < (now + p - 1)/p/*向上取整*/ && !flag[t.x][t.y])
        {
            flag[t.x][t.y] = 1;
            now += s[t.x][t.y];
        }
        else
        {
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            int x2 = t.x + dx[i];
            int y2 = t.y + dy[i];
            if(x2 < 1 || x2 > n || y2 < 1 || y2 > m)
            {
                continue;
            }
            if(flag[x2][y2])
            {
                continue;
            }
            q.push({x2, y2});
        }
    }
    cout << now;
    return 0;
}