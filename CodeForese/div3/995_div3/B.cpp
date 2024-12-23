#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 0;
    int total = a + b + c;
    if( total > n)
    {
        if( a >= n)
        {
            cout << "1\n";
        }
        else if(a + b >= n)
        {
            cout << "2\n";
        }
        else
        {
            cout << "3\n";
        }
        return;
    }
    if(n % total == 0)
    {
        cout << n / total * 3 << "\n";
        return;
    }
    else
    {
        int other = n % total;
        n /= total;
        ans = n * 3;
        if(a >= other)
        {
            ans++;
        }
        else if(a+b >= other)
        {
            ans += 2;
        }
        else
        {
            ans += 3;
        }
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