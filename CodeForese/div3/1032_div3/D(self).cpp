#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                ans.push_back({1, j});
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(b[j] > b[j+1])
            {
                swap(b[j], b[j+1]);
                ans.push_back({2, j});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > b[i])
        {
            swap(a[i], b[i]);
            ans.push_back({3, i});
        }
    }
    cout << ans.size() << endl;
    for(auto [x, y] : ans)
    {
        cout << x << " " << y << endl;
    }
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