#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> ks(n);
    for(int _ = 0; _ < 2; _++)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> ks[i];
        }
    }
    // 各二项式系数的和是2的n次方
    vector<int> ans(1 + *max_element(ks.begin(), ks.end()), 1);
    for(int i = 1; i < (int)ans.size(); i++)
    {
        ans[i] = (2ll * ans[i - 1] % mod);
    }
    for(int k : ks)
    {
        cout << ans[k] << "\n";
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}