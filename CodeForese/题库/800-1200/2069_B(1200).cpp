#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> num(n*m+10, 0), other(n*m+10, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            num[a[i][j]] = 1;
            if(i+1 < n && a[i+1][j] == a[i][j])
            {
                other[a[i][j]] = 1;
            }
            if(j+1 < m && a[i][j+1] == a[i][j])
            {
                other[a[i][j]] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n*m; i++)
    {
        ans += num[i];
        ans += other[i];
    }
    ans = ans - (int)(*(max_element(other.begin(), other.end()))) - 1;
    cout << ans << endl;
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