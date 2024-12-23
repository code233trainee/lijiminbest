#include <bits/stdc++.h>
using namespace std;
char a[6][6];
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
bool f(int x, int y)
{
    bool t = false;
    for(int k = 0; k < 8; k++)
    {
        if((a[x+dx[k]][y+dy[k]] == 'x' && a[x+dx[k]*2][y+dy[k]*2] == 'x')//在下点的外围
            || (a[x+dx[k]][y+dy[k]] == 'x' && a[x-dx[k]][y-dy[k]] == 'x'))//在下点的两边
            // || (a[x-dx[k]][y-dy[k]] == 'x' && a[x-dx[k]*2][y-dy[k]*2] == 'x')) 这一段是多余的
            {
                t = true;
            }
    }
    return t;
}
int main()
{
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            cin >> a[i][j];
        }
    }
    bool ok = false;
    int cnt = 0;
    for(int i = 0; i <= 4; i++)
    {
        for(int j = 0; j <= 4; j++)
        {
            if(a[i][j] == '.')
            {
                a[i][j] = 'x';
                if(f(i, j))
                {
                    cout << "YES\n";
                    return 0;
                }
                else
                {
                    a[i][j] = '.';
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}