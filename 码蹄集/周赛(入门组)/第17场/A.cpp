#include <bits/stdc++.h>
using namespace std;
void solve()
{

    int n, m;
    cin >> n >> m;
    vector<string> name(n);
    vector<int> b(m);
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<string, int>> Att(m);
    for(int i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        Att[i] = {s, i};
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> vp(n);
    for(int i = 0; i < n; i++)
    {
        int total = 0;
        for(int j = 0; j < m; j++)
        {
            total += b[j] * a[i][j];
        }
        vp[i] = {total, i+1};
    }
    sort(Att.begin(), Att.end());
    auto cmp = [&](pair<int, int> v1, pair<int, int> v2)
    {
        if(v1.first != v2.first)
        {
            return v1.first > v2.first;
        }
        else
        {
            if(a[v1.second-1][Att[0].second] != a[v2.second-1][Att[0].second])
            {
                return a[v1.second-1][Att[0].second] > a[v2.second-1][Att[0].second];
            }
            else
            {
                return name[v1.second-1] > name[v2.second-1];
            }
        }
    };
    sort(vp.begin(), vp.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        cout << vp[i].second << " \n"[i == n-1];
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}