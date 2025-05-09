#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mx = 0;
    int res = 0;
    for(auto &z : a)
    {
        if(mx > z)
        {
            res = max(res, mx + z);
        }
        mx = max(mx, z);
    }
    cout << mx << endl;
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