#include <bits/stdc++.h>
using namespace std;
int ma[6][6];
bool temp[6][6];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int total,fx,fy,sx,sy,T,l,r;
int n, m, t;
void walk(int x, int y)
{
    if(x==fx && y==fy)
    {
        total++;
        return;
    }
    else
    {
        for(int i = 0; i <= 3; i++)
        {
            if(temp[x+dx[i]][y+dy[i]] == 0 && ma[x+dx[i]][y+dy[i]] == 1)
            {
                temp[x][y] = 1;
                walk(x+dx[i],y+dy[i]);
                temp[x][y] = 0;
            }
        }
    }
}
int main()
{
    std::cin >> m >> n >> t;
    for(int ix = 1; ix <= n; ix++)
    {
        for(int iy = 1; iy <= m; iy++)
        {
            ma[ix][iy] = 1;
        }
    }
    cin >> sx >> sy;
    cin >> fx >> fy;
    for(int u = 1; u <= t; u++)
    {
        cin >> l >> r;
        ma[l][r] = 0;
    }
    // auto work = [&](auto &&self ,int x, int y){
    //     if(x==sx && y== sy)
    //     {
    //         total++;
    //         return;
    //     }
    //     else
    //     {
    //         for(int i = 0; i <= 3; i++)
    //         {
    //             if(temp[x+dx[i]][y+dy[i]] == 0 && ma[x+dx[i]][y+dy[i]] == 1)
    //             {
    //                 temp[x][y] = 1;
    //                 self(self ,x+dx[i],y+dy[i]);
    //                 temp[x][y] = 0;
    //             }
    //         }
    //     }
    // };
    // work(work, sx, sy);
    walk(sx, sy);
    cout << total;
    return 0;
}