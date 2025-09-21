#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    // // 暴力
    // int n;
    // cin >> n;
    // vector<vector<int>> a(n);
    // int mx = -1;
    // for(int i = 0; i < n; i++)
    // {
    //     int len;
    //     cin >> len;
    //     mx = max(mx, len);
    //     for(int j = 0; j < len; j++)
    //     {
    //         int x;
    //         cin >> x;
    //         a[i].push_back(x);
    //     }
    // }
    // vector<int> res;
    // while(res.size() < mx)
    // {
    //     int now = res.size();
    //     sort(a.begin(), a.end());
    //     for(int i = 0; i < a[0].size(); i++)
    //     {
    //         res.push_back(a[0][i]);
    //     }
    //     vector<vector<int>> tmp;
    //     for(int i = 0; i < a.size(); i++)
    //     {
    //         if(a[i].size() > res.size() - now)
    //         {
    //             vector<int> tmp1;
    //             for(int j = res.size() - now; j < a[i].size(); j++)
    //             {
    //                 tmp1.push_back(a[i][j]);
    //             }
    //             tmp.push_back(tmp1);
    //         }
    //     }
    //     a = tmp;
    // }
    // for(int i = 0; i < mx; i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";

    //正解
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        for(int j = 0; j < len; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
    {
        pos[i] = i;
    }
    sort(pos.begin(), pos.end(), [&](auto x, auto y) -> bool{
        return a[x].size() < a[y].size();
    });

    int bi = 0;
    int w = 0;
    while(true)
    {
        while(bi < n && a[pos[bi]].size() <= w)
        {
            bi++;
        }
        if(bi >= n) 
        {
            break;
        }
        vector<int> c;
        for(int i = bi; i < n; i++)
        {
            c.push_back(pos[i]);
        }
        while(true)
        {
            vector<int> nc;
            int t = 1e9;
            for(int x : c)
            {
                if(a[x][w] < t)
                {
                    t = a[x][w];
                    nc.clear();
                    nc.push_back(x);
                }
                else if(t == a[x][w])
                {
                    nc.push_back(x);
                }
            }
            // if(nc.empty()) break;
            cout << a[nc[0]][w] << " ";
            w++;
            if(w == a[nc[0]].size()) break;
            c = nc;
        }
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}