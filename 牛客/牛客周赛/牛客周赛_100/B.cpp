#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<bool> vis(n+1, false);
    vector<int> a, b;
    for(int i = 1; i <= n * 2; i++)
    {
        int x;
        cin >> x;
        if(!vis[x])
        {
            a.push_back(x);
            vis[x] = true;
        }
        else
        {
            b.push_back(x);
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
    for(int i = 0; i < n; i++) cout << b[i] << " \n"[i == n-1];
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