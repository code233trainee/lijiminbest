#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    map<int, set<int>> ma;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            if(x == min(i, j))
            {
                ans++;
            }
            ma[min(i, j)].insert(x);
        }
    }
    for(auto [k, st] : ma)
    {
        for(auto ss : st)
        {
            if(ss != k && ma.find(k) != ma.end() && ma[ss].find(k) != ma[ss].end())
            {
                cout << ans + 2 << endl;
                return 0;
            }
        }
    }
     for(auto [k, st] : ma)
    {
        for(auto ss : st)
        {
            if(ss != k && ma.find(ss) != ma.end() && (ma[ss].size() >= 2 || ma[ss].size() == 1 && *ma[ss].begin() != ss))
            {
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}