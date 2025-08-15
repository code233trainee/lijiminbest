#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 对于一个01串，首尾不同，则01和10字串的数量也不同
void solve()
{
    int n;
    cin >> n;
    vector<int> deg(n+1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }   
    string s;
    cin >> s;
    s = "$" + s;
    int x = 0, y = 0, z = 0, w = 0;
    for(int i = 2; i <= n; i++)
    {
        if(deg[i] == 1)
        {
            if(s[i] == '?')
            {
                z += 1;
            }
            else if(s[i] == '0')
            {
                x += 1;
            }
            else if(s[i] == '1')
            {
                y += 1;
            }
        }
        else if(s[i] == '?')
        {
            w += 1;
        }
    }
    if(s[1] == '0')
    {
        cout << (y + (z + 1) / 2) << endl;
    }
    else if(s[1] == '1')
    {
        cout << (x + (z + 1) / 2) << endl;
    }
    else
    {
        cout << (max(x, y) + (z + (x == y ? w % 2 : 0)) / 2) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}