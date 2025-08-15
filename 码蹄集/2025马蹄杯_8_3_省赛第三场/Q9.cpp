#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<deque<int>> va(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int y;
            cin >> y;
            va[i].push_back(y);
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int op, x, k;
        cin >> op >> x >> k;
        x--;
        k = k % m;
        if(op == 1)
        {
            for(int i = 0; i < k; i++)
            {
                int y = va[x].front();
                va[x].pop_front();
                va[x].emplace_back(y);
            }
        }
        else
        {
            for(int i = 0; i < k; i++)
            {
                int y = va[x].back();
                va[x].pop_back();
                va[x].emplace_front(y);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << va[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}