#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int i = 0;
    for(; i < n; i++)
    {
        x += (s[i] == 'L' ? -1 : +1);
        k--;
        if(!x)
        {
            break;
        }
    }
    ll ans = 0;
    if(!x)
    {
        ans = 1;
        for(int j = 0; j < n; j++)
        {
            x += (s[j] == 'L' ? -1 : +1);
            if(!x)
            {
                ans += (k)/(j+1);
                break;
            }
        }
    }
    cout << ans << endl;
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