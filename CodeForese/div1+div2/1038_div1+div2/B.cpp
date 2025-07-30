#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a <= c && b <= d)
        {
            // ignore
        }
        else if(b <= d)
        {
            res += a - c;
        }
        else
        {
            res += b - d + a;
        }
    }
    cout << res << endl;
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