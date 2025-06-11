//https://codeforces.com/problemset/problem/2075/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> b(n);
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b[i] = x;
    }
    ll ans = 0;
    if(k <= 1)
    {
        ll l = *(max_element(b.begin(), b.end() - 1));
        ll r = *(max_element(b.begin() + 1, b.end()));
        ans = max(l+b[n-1], r + b[0]);
    }
    else //只要k大于等于2，我们就可以选择最边缘的数字k个，然后必然可以选到前k+1个大的数值，这是能选到的最大的值了
    {
        sort(b.begin(), b.end(), greater<ll>()); // 从大到小
        //默认：sort(b.begin(), b.end(), less<ll>()); 从小到大
        ans = accumulate(b.begin(), b.begin() + k + 1, 0ll);
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
    return 0;
}