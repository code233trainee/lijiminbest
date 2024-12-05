#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k;
    cin >> n >> k;
    if(k == 1)
    {
        cout << n << endl;
        return;
    }
    int ans = 0;
    while(n)
    {
        ans += n % k;
        n /= k;
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}