#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//最大公因数
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//找到最小的质因数
ll get(ll n) {
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    if(a == 1 || b == 1)
    {
        cout << "-1\n";
        return;
    }
    ll g = gcd(a, b);
    ll mx = get(a);
    ll my = get(b);
    ll ans = my * mx;
    if(g > 1)
    {
        ans = min(ans, get(g));
    }
    cout << ans << "\n";
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