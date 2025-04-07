#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    ll m;
    cin >> m;
    vector<ll> cf(n+2);
    ll sum1 = 0, sum2 = 0;
    while(m--)
    {
        ll l, r;
        cin >> l >> r;
        sum1 += sum[r] - sum[l-1];
        cf[l]++;
        cf[r+1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        cf[i] = cf[i-1] + cf[i]; 
    }
    sort(cf.begin() + 1, cf.end() - 1);
    sort(a.begin() + 1, a.end());
    for(int i = n; i >= 1; i--)
    {
        sum2 += a[i] * cf[i];
    }
    cout << sum2 - sum1;
    return 0;
}