#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll m;
    cin >> n >> m;
    if(m < n || m > ll(n) * (n+1) / 2)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = n; i >= 1; i--)
    {
        ll t = ll(n + i) * (n - i + 1) / 2 + i - 1;
        if(t >= m)
        {
            ll cut = i - (t - m);
            if(i == n)
            {
                cout << cut << endl;
            }
            else
            {
                cout << n << endl;
                for(int j = n; j >= i + 2; j--)
                {
                    cout << j << " " << j - 1 << endl;
                }
                cout << i + 1 << " " << cut << endl;
            }
            if(cut > 1)
            {
                cout << cut << " " << 1 << endl;
            }
            for(int j = 1, last = 1; j <= i; j++)
            {
                if(j == last || j == cut)
                {
                    continue;
                }
                cout << last << " " << j << endl;
                last = j;
            }
            return;
        }
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