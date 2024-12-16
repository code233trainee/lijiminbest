#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005], b[100005];
int main()
{
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        b[i] = b[i-1] + t;
    }
    ll ans = 0;
    //当a≡b(mod k)时，|a-b|mod k = 0; 因为(a mod k - b mod k) mod k = (a - b) mod k;
    //这里要从0开始,因为0的位置也能和后面的下标构成满足条件的子序列
    for(int i = 0; i <= n; i++)
    {
        ans += a[b[i] % k]++;
    }
    cout << ans << "\n";
    return 0;
}