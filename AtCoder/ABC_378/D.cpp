#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> v(h);
    for(int i = 0; i < h; i++)
    {
        cin >> v[i];
    }
    long long ans = 0;
    auto Dfs = [&](auto&& myself, int i, int j, int t) -> void{ // (->)是指定返回值类型，如果不要->则会自动推断返回值类型
        if(t == 0)
        {
            ans++;
            return;
        }
        v[i][j] = '$';//防止选到自己
        for(int ni = -1; ni <= 1; ni++)
        {
            for(int nj = -1; nj <= 1; nj++)
            {
                //只关注上下左右
                if((ni * ni) + (nj * nj) == 1)
                {
                    auto di = ni + i;
                    auto dj = nj + j;
                    if(di >= 0 && dj >= 0 && di < h && dj < w)
                    {
                        if(v[di][dj] == '.')
                        {
                            myself(myself, di, dj, t - 1);
                        }
                    }
                }
            }
        }
        v[i][j] = '.';
    };
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(v[i][j] == '.')
            {
                Dfs(Dfs, i, j, k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}