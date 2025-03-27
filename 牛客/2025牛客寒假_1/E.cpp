#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll check(vector<ll> &a, ll l, ll r)
{
    ll n = a.size() - 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i <= n/2)
        {
            ans += abs(l - a[i]);
        }
        else
        {
            ans += abs(r - a[i]);
        }
    }
    return ans;
}
void solve()
{
    //中位数时需要的操作最小
    //中位数相等就需要判断一下l-1时，和r+1时哪个的操作最小
    //此题就相当于每个点的权值都是1

    //如果是带权的，则我们需要找到刚好大于总人数的一半的位置
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = 0;
    if((n / 2) % 2 == 0)
    {
        l = (a[n/4] + a[n/4 + 1]) / 2;
        r = (a[n - n/4] + a[n - n/4 + 1]) / 2;
    }
    else
    {
        l = a[n/4 + 1];
        r = a[n - n/4];
    }
    if(l == r)
    {
        if(check(a, l-1, r) < check(a, l, r + 1))
        {
            cout << check(a, l-1, r) << "\n";
        }
        else
        {
            cout << check(a, l, r + 1) << "\n";
        }
    }
    else
    {
        cout << check(a, l, r) << "\n";
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}