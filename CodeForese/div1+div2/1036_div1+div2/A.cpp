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
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                res = {a[i], a[j]};
            }
        }
    }
    if(res.empty())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << 2 << "\n";
        cout << res[0] << " " << res[1] << "\n";
    }
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