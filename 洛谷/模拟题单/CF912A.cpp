#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll a, b;
    cin >> a >> b;
    ll x, y, z;
    cin >> x >> y >> z;
    ll na = 0, nb = 0;
    na = 2*x + y;
    nb = 3*z + y;
    ll ans = max(0ll, na - a) + max(0ll, nb - b);
    cout << ans << "\n";
    return 0;
}