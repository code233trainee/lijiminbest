#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    if(n == 1)
    {
        cout << "1\n";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m-1; j++)
        {
            if(a[i][j+1] - a[i][j] == 1)
            {
                cout << "-1\n";
                return;
            }
        }
    }

    vector<int> ans(n+1);
    for(int i = 0; i < n; i++)
    {
        ans[a[i][0]+1] = i+1;
    }                          
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }             
    cout << "\n";
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