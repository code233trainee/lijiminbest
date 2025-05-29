#include <bits/stdc++.h>
// P5663 加工零件
// 求起点到所有点的(*奇数步最短路)和(偶数步最短路)
// 如果使用奇数个A内的奇数和所有偶数>=奇数步最短路
// 或者使用偶数个A内的奇数和所有偶数>=偶数步最短路
// 输出1
using namespace std;
using ll = long long;
const int maxn = 2e6 + 5;
int n, m, q;
int dis[maxn][2];
vector<int> e[maxn];
const int M = 2e9 + 8; // 大于2e9;
void bfs(int x)
{
    int step = 1;
    queue<int> q;
    q.push(x); 
    // for (int i = 1; i <= n; i++) vis[i] = false;
    while(!q.empty())
    {
        int s = q.size();
        //分层遍历，将每一层遍历完，再进入下一层遍历
        for(int i = 0; i < s; i++)
        {
            int now = q.front();
            q.pop();
            for(int j = 0; j < e[now].size(); j++)
            {
                int nxt = e[now][j];
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
void solve()
{
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++)
    {
        e[i].clear();
    }

    vector<int> odds;
    ll sum = 0, odd_sum, even_sum;
    // odd_sum: 走奇数步最多能走多少步
    // even_sum: 走偶数步最多能走多少步
    for(int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if(x % 2 == 1)
        {
            odds.push_back(x);
        }
        sum += x;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    sort(odds.begin(), odds.end());
    int num = odds.size();
    if(num == 0)
    {
        // 如果没有奇数
        odd_sum = 0;
        even_sum = sum;
    }
    else if(num % 2 == 0)
    {
        even_sum = sum;
        odd_sum = sum - odds[0];
    }
    else
    {
        even_sum = sum - odds[0];
        odd_sum = sum;
    }

    for(int i = 2; i <= n; i++)
    {
        dis[i][0] = dis[i][1] = M;
    }
    dis[1][0] = 0;
    dis[1][1] = M;// 一个不可能的数
    bfs(1);

    // for(int i = 1; i <= n; i++)
    // {
    //     cout << dis[i][0] << " " << dis[i][1] << endl;
    // }
    for(int i = 1; i <= n; i++)
    {
        if(dis[i][0] <= even_sum || dis[i][1] <= odd_sum)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}