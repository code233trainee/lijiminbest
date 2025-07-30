#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), [](auto &x, auto &y) -> bool{
        return x[2] < y[2];
    });
    for(auto &z : a)
    {
        if(k >= z[0] && k <= z[1])
        {
            k = max(k, z[2]);
        }
    }
    cout << k << endl;
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