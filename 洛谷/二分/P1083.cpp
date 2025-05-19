#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // 订单数量有很多，由于我们需要找到第一个不能满足的订单
    // 当然，如果有一个订单无法完成，那么在这个订单之后的订单都是无法完成的
    // 所以我们可以二分的去找第一个无法满足的订单，就可以直接输出答案
    ll n, m;
    cin >> n >> m;
    vector<ll> r(n+1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    vector<ll> d(m+1), s(m+1), t(m+1);
    for(ll i = 1; i <= m; i++)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    auto check = [&](ll x) -> bool{
        vector<ll> diff(n+2);
        vector<ll> need(n+1);
        for(ll i = 1; i <= x; i++)
        {
            diff[s[i]] += d[i];
            diff[t[i] + 1] -= d[i];
        }
        for(ll i = 1; i <= n; i++)
        {
            need[i] = need[i-1] + diff[i];
            if(need[i] > r[i])
            {
                return false;
            }
        }
        return true;
    };
    if(check(m))
    {
        cout << "0\n";
        return 0;
    }
    ll L = 1, R = m;
    while(L < R)
    {
        ll mid = (L + R) >> 1;
        if(check(mid))
        {
            L = mid + 1;
        }
        else
        {
            R = mid;
        }
    }
    cout << "-1\n" << L;
    return 0;
}