#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int t, n, m, a[N][N];

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, -1, 0, +1};

inline bool in(int i, int j)
{
    return(0 <= i && i < n && 0 <= j && j < m);
}
void solve()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int mx = 0;
            for(int k = 0; k < 4; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(in(ni, nj))
                {
                    mx = max(mx, a[ni][nj]);
                }
            }
            a[i][j] = min(a[i][j], mx);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        solve();
    }
}