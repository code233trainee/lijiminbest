#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int bx, by, mx, my;
ll f[40][40];
bool flag[40][40];
int main()
{
    cin >> bx >> by >> mx >> my;
    bx += 2;
    by += 2;
    mx += 2;
    my += 2;
    f[2][1] = 1;
    flag[mx][my] = 1;
    for(int i = 1; i <= 8; i++)
    {
        flag[mx+dx[i]][my+dy[i]] = 1;
    }
    for(int i = 2; i <= bx; i++)
    {
        for(int j = 2; j <= by; j++)
        {
            if(flag[i][j])
            {
                continue;
            }
            f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }
    cout << f[bx][by] << endl;
    return 0;
}