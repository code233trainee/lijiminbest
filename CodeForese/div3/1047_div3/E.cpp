#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> cnt(n+1);
    vector<ll> last(n+1, -1), next(n+1, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    while(k)
    {
        k--;
        int now = 0;
        while(cnt[now]) now++;
        next.assign(n+1, 0);//重新赋值为全0
        for(int i = 0; i <= n; i++)
        {
            if(i < now && cnt[i] == 1)
            {
                next[i] += cnt[i];
            }
            else
            {
                next[now] += cnt[i];
            }
        }
        if(last == next)
        {
            break;
        }
        last = cnt;
        cnt = next;
    }

    // last cnt next
    // 上次 当前 下次
    auto res = cnt;
    if(k % 2 == 0) 
    {
        res = next;
    }
    else
    {
        res = cnt;
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++)
    {
        ans += (ll)i * res[i];
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}