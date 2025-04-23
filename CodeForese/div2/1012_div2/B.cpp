#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int vis[55][55];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(s[i][j] == '0')
            {
                break;
            }
            vis[i][j] = 1;
        }
    }
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(s[i][j] == '0')
            {
                break;
            }
            vis[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == '1' && vis[i][j] == 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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