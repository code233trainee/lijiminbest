#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> d(n), b(n);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        d[x].push_back(y);
        b[y].push_back(x);
    }

    //f[i][j], 如果从节点i开始走，玩家j能不能赢(0:Alice, 1:Bob), 
    vector<vector<bool>> f(n, vector<bool>(2, true));
    //与i相连的会失败的孩子数量
    vector<vector<int>> c(n, vector<int>(2, 0));

    auto check = [&](auto &&self, int x, int w) -> void {
        if(!f[x][w]) return;
        f[x][w] = false;
        for(int y : b[x])
        {
            c[y][1 - w]++;
            if(1 - w == 0)
            {
                if(c[y][1 - w] == d[y].size())
                {
                    self(self, y, 1 - w);
                }
            }
            else
            {
                self(self, y, 1 - w);
            }
        }
    };

    while(q--)
    {
        int tp, u;
        cin >> tp >> u;
        u--;
        if(tp == 1)
        {
            check(check, u, 0);
            check(check, u, 1);
        }
        else
        {
            cout << (f[u][0] ? "YES" : "NO") << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}