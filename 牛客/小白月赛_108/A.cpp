#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll left = 0;
    ll right = 3e9;
    while(left <= right)
    {
        ll mid = (left + right) >> 1;
        ll c = (mid + 1) / 2 + 1ll * (mid / 2) * x;
        if(c >= y)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}