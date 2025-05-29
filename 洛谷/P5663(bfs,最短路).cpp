#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e9+5;
const int maxn = 1e5 + 10;
vector<int> v[100010];
// int odd[100010],even[100010];
int dis[maxn][2];
void bfs(int x)
{
    // memset(odd, 0x3f, sizeof(odd));
    // memset(even, 0x3f, sizeof(even));

    // queue<pair<int, int>> q;
    // for(int i = 0; i < v[1].size(); i++)
    // {
    //     //奇数
    //     odd[v[1][i]] = 1;
    //     q.push(make_pair(v[1][i], 1));
    // }
    // while(!q.empty())
    // {
    //     int x = q.front().first;
    //     int y = q.front().second;
    //     q.pop();
    //     for(int i = 0; i < v[x].size(); i++)
    //     {
    //         if(y % 2 == 1)
    //         {
    //             if(y+1 < even[v[x][i]])
    //             {
    //                 even[v[x][i]] = y+1;
    //                 q.push(make_pair(v[x][i], y + 1));
    //             }
    //         }
    //         else
    //         {
    //             if(y + 1 < odd[v[x][i]])
    //             {
    //                 odd[v[x][i]] = y+1;
    //                 q.push(make_pair(v[x][i], y + 1));
    //             }
    //         }
    //     }
    // }
    int step = 1;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int s = q.size();
        for(int i = 0; i < s; i++)
        {
            int now = q.front();
            q.pop();
            for(int j = 0; j < v[now].size(); j++)
            {
                int nxt = v[now][j];
                if(dis[nxt][step % 2] == M)
                {
                    q.push(nxt);
                    dis[nxt][step % 2] = step;
                }
            }
        }
        step++;
    }
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
    {
        dis[i][0] = dis[i][1] = M;
    }
    dis[1][0] = 0;
    dis[1][1] = M;
    bfs(1);
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << dis[i][0] << " " << dis[i][1] << endl;
    // }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(y % 2 == 0)
        {
            if(dis[x][0] > y)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
        else
        {
            if(dis[x][1] > y)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}