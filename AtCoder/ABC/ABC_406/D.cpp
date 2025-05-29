#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n+1);
    vector<vector<int>> b(m+1);
    vector<bool> ux(n + 1), uy(m + 1);
    vector<bool> used(k);
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(i);
        b[y].push_back(i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            cin >> x;
            if(ux[x])
            {
                cout << "0\n";
            }
            else
            {
                int ans = 0;
                for(int e : a[x])
                {
                    if(!used[e])
                    {
                        used[e] = true;
                        ans++;
                    }
                }
                ux[x] = true;
                cout << ans << "\n";
            }
        }
        else
        {
            int y;
            cin >> y;
            if(uy[y])
            {
                cout << "0\n";
            }
            else
            {
                
                int ans = 0;
                for(int e : b[y])
                {
                    if(!used[e])
                    {
                        used[e] = true;
                        ans++;
                    }
                }
                uy[y] = true;
                cout << ans << "\n";
            }
        }
    }
    return 0;
}