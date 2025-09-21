#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
struct Node
{
    int val, x, y;

    bool operator<(const Node & n) const
    {
        return val > n.val;
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    vector<pair<int, int>> que(q + 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int qq;
        cin >> qq;
        que[i].first = qq;
        que[i].second = i;
    }
    sort(que.begin() + 1, que.end());
    priority_queue<Node> pq;
    for(int j = 1; j <= m; j++)
    {
        pq.push({v[1][j], 1, j});
    }

    int sum = 0;
    vector<int> ans(q+1);
    for(int i = 1; i <= q; i++)
    {
        auto [cur, id] = que[i];
        while(pq.size() && pq.top().val <= cur)
        {
            int X = pq.top().x;
            int Y = pq.top().y;
            pq.pop();
            if(vis[X][Y]) continue;
            vis[X][Y] = true;
            sum++;
            for(int k = 0; k < 4; k++)
            {
                int nx = X + dx[k];
                int ny = Y + dy[k];
                if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
                pq.push({v[nx][ny], nx, ny});
            }
        }
        ans[id] = sum;
    }

    for(int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
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