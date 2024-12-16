#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
int main()
{
    ll n;
    cin >> n;
    n--;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = (ans + (n - i + 1) * (n - i + 1) * i) % mod;
    }
    cout << ans << "\n";
    return 0;
}