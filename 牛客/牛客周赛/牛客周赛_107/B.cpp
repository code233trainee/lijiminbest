#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>());
    for(int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, a[i][1] - a[i][0] + 1);
    }
    cout << mx << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}