#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    vector<ll> suf(n+1);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = n-1; i >= 0; i--)
    {
        suf[i] = suf[i+1] + a[i];
    }
    sort(suf.begin(), suf.end());
    ll total = sum;
    sum *= k;
    if(sum < x)
    {
        cout << "0\n";
        return;
    }
    ll ans = 0;
    ll cnt = 0;
    while(sum >= x)
    {
        sum -= total;
        cnt++;
    }
    ll mask = x - sum;
    //大于等于
    ll indx = lower_bound(suf.begin(), suf.end(), mask) - suf.begin();
    ans = (cnt-1) * n + (suf.size() - indx);
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