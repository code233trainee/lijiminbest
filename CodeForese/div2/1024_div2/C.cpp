#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, -1));
    int now = 1;
    int x = 0;
    int y = 0;
    int dir = 0;
    auto check = [&](int x, int y) -> bool {
        if(x < 0 || x > n-1 || y < 0 || y > n-1 || a[x][y] != -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    };
    while(now <= n * n)
    {
        a[x][y] = now;
        now++;
        if(check(x + dx[dir%4], y + dy[dir%4]))
        {
            x = x + dx[dir%4];
            y = y + dy[dir%4];
        }
        else
        {
            dir++;
            x = x + dx[dir%4];
            y = y + dy[dir%4];
        }
    }
    int change = n*n; 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << change - a[i][j] << " ";
        }
        cout << "\n";
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}