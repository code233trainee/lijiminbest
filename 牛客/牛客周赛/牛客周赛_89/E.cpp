#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(a[i][j-1] == '0')
            {
                a[i][j] = '1' - a[i][j] + '0';
                a[i][j-1] = '1' - a[i][j-1] + '0';
                ans.push_back({i, j-1, i, j});
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i-1][m-1] == '0')
        {
            a[i-1][m-1] = '1' - a[i-1][m-1] + '0';
            a[i][m-1] = '1' - a[i][m-1] + '0';
            ans.push_back({i - 1, m-1, i, m-1});
        }
    }
    if(a[n-1][m-1] == '0') {
        cout << "-1\n";
    } else {
        cout << ans.size() << endl;
        for(auto v : ans)
        {
            for(auto j : v)
            {
                cout << j + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}