#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 10;
ll n, m, a[N], b[N];
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+2, a+1+n);
    vector<ll> tmp;
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        //问题难度严格大于第一个的
        if(x > a[1])
        {
            tmp.push_back(x);
        }
    }
    int sz = tmp.size();
    sort(tmp.begin(), tmp.end());
    vector<ll> s(sz);
    ll now = n;
    for(int i = sz - 1; i >= 0; i--)
    {
        while(now > 1 && a[now] >= tmp[i])
        {
            now--;
        }
        s[i] = n - now;
    }
    for(int i = 1; i <= m; i++)
    {
        ll res = m/i;
        for(int j = m%i; j < sz; j += i)
        {
            res += s[j];
        }
        cout << res << " \n"[i == m];
    }
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