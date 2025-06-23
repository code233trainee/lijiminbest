#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<bool> vis(1e5+10);
    for(int i = 1; i <= m; i++)
    {
        if(!vis[n % i])
        {
            vis[n % i] = true;
        }
        else
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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