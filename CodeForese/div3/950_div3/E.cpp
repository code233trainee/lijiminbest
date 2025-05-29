#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    // a,b数组中，每个数字所在的行和列
    vector<int> pos1i(n*m), pos2i(n*m), pos1j(n*m), pos2j(n*m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x = a[i][j] - 1;
            int y = b[i][j] - 1;
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    } 
    // 储存每个每个数字需要替换到哪一行，哪一列
    vector<set<int>> pi(n*m), pj(n*m);
    for(int x = 0; x < n * m; x++)
    {
        int i1 = pos1i[x], i2 = pos2i[x];
        int j1 = pos1j[x], j2 = pos2j[x];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }
    for(int x = 0; x < n * m; x++)
    {
        if(pi[x].size() > 1 || pj[x].size() > 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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