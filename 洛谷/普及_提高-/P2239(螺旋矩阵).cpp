#include <bits/stdc++.h>
using namespace std;
int a[2005][2005];
int main()
{
    int dx[]={0, 1, 0, -1};
    int dy[]={1, 0, -1, 0};
    int n;
    cin >> n;
    
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
    int i, j;
    cin >> i >> j;
    cout << a[i-1][j-1];
    return 0;
}