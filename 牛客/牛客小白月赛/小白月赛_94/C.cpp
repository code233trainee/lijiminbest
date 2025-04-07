#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> s(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        //这里要注意前缀和如何获取第a[i+1]到a[n]的和
        ll sum = max(s[i-1], s[n] - s[i]) - a[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}