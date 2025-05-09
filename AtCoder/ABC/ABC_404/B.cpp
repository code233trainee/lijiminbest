#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n;
char s[4][N][N],t[N][N];
void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> s[0][i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++) 
            {
                s[i+1][y][n-x-1]=s[i][x][y];
            }
        } 
    }
    int ans = 1e7;
    for(int x = 0; x < 4; x++)
    {
        int total = x;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(s[x][i][j] != t[i][j])
                {
                    total += 1;
                }
            }
        }
        ans = min(ans, total);
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}