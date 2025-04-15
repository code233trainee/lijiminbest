#include <bits/stdc++.h>
using namespace std;
const int mx = INT_MAX;
const int N = 1010;
int dis[N][N], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    //第一个参数是要填充的数组
    //第二个参数是填充的内容(memset只取低8位)
    //第三个参数是填充的数量(字节),这里就是填满整个数组
    //63的16进制是0x3F，一个int四个字节，所以对于每个元素填充的就是0x3f3f3f3f,是一个特别大的数字
    memset(dis, 63, sizeof(dis));//按字节填充数组
    queue<pair<int, int>> qu;
    int ans = 0;
    vector<string> a(h);
    for(int i = 0; i < h; i++)
    {
        cin >> a[i];
        for(int j = 0; j < w; j++)
        {
            if(a[i][j] == 'H')
            {
                dis[i][j] = 0;
                qu.push(make_pair(i, j));
            }
        }
    }
    while(!qu.empty())
    {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();
        for(int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            //                              这里的处理是为了每次取最小的值，这样即便是两个不同的出发点到达了同一个地方也只取最近的距离
            if(tx >= 0 && tx < h && ty >= 0 && ty < w && a[tx][ty] == '.' && dis[tx][ty] > dis[x][y] + 1)
            {
                dis[tx][ty] = dis[x][y]+1;
                qu.push(make_pair(tx, ty));
            }
        }
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            ans += (dis[i][j] <= d);
        }
    }
    cout << ans;
    return 0;
}