// https://codeforces.com/problemset/problem/1675/D
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n+1);
    vector<bool> leaf(n+1, true);
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        leaf[b[i]] = false;
    }
    if(n == 1)
    {
        cout << "1\n1\n1\n\n";
        return;
    }

    vector<vector<int>> path(n+1);
    vector<bool> used(n+1, false);
    int color = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!leaf[i])
        {
            continue;
        }
        used[i] = true;
        path[color].emplace_back(i);

        int v = i;
        while(b[v] != v && !used[b[v]])
        {
            v = b[v];
            used[v] = true;
            path[color].emplace_back(v);
        }
        color++;
    }
    cout << color << "\n";
    for(auto &z : path)
    {
        if(z.empty())
        {
            continue;
        }
        cout << (int)z.size() << "\n";
        reverse(z.begin(), z.end());
        for(auto &y : z)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}