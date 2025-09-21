#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> go = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    map<pair<int, int>, int> mp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            int dx = x[i] + go[j][0];
            int dy = y[i] + go[j][1];
            mp[{dx, dy}]++;
        }
    }
    pair<int, int> ans;
    int mx = 0;
    for(auto z : mp)
    {
        if(z.second > mx && z.first.first > 0 && z.first.second > 0)
        {
            mx = z.second;
            ans = z.first;
        }
    }
    cout << ans.first << " " << ans.second << endl;
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