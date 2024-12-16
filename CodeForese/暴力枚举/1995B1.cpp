#include <bits/stdc++.h>
#define ll long long
int a[200001];
void solve()
{
    ll n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a+1, a+n+1);
    ll ans = 0;
    ll i = 0;
    ll j = 1;
    ll x = 0;
    //原理就是，先把能买的买上(因为是排序过的)
    //i是右端点，j是左端点(条件不满足时需要缩小的点)
    while(i < n)
    {
        i++;
        x += a[i];
        while(x > m || a[i]-a[j] > 1)
        {
            x -= a[j];
            j++;
        }
        ans = std::max(ans, x);
    }
    std::cout << ans << "\n";
}
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}