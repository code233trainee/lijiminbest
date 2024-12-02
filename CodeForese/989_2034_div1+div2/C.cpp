#include <bits/stdc++.h>
using namespace std;

//tourist`s code
const string let = "LRUD?";
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    vector<vector<int>> g(h * w + 1);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            int p = int(let.find(s[i][j]));
            if(p < 4)
            {
                int ni = i + di[p];
                int nj = j + dj[p];
                if(ni >= 0 && nj >= 0 && ni < h && nj < w)
                {
                    g[ni * w + nj].push_back(i * w + j);
                }
                else
                {
                    g[h * w].push_back(i * w + j);
                }
            }
        }
    }
    vector<bool> was(h * w + 1, false);
    vector<int> que(1, h * w);
    was[h * w] = true;
    for(int b = 0; b < int(que.size()); b++)
    {
        for(int x : g[que[b]])
        {
            if(!was[x])
            {
                que.push_back(x);
                was[x] = true;
            }
        }
    }
    int ans = h * w + 1 - int(que.size());
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(s[i][j] == '?')
            {
                bool good = false;
                for(int dir = 0; dir < 4; dir++)
                {
                    int ni = i + di[dir];
                    int nj = j + dj[dir];
                    if(ni >= 0 && nj >= 0 && ni < h && nj < w)
                    {
                        if(!was[ni * w + nj])
                        {
                            good = true;
                            break;
                        }
                    }
                }
                if(!good)
                {
                    ans -= 1;
                }
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}