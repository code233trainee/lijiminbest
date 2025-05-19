#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e6 + 10;
int a[N], pre[N], suf[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        suf[i] = pre[i] = 0;
    }
    int now = 0;
    set<int> s;
    for(int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    for(int i = 1; i <= n; i++)
    {
        // 找到第一个大于a[i]的位置;
        auto it = s.upper_bound(a[i]);
        if(it == s.begin())
        {
            continue;
        }
        now++;
        pre[now] = i;
        s.erase(--it); 
    }

    s.clear();
    now = 0;
    for(int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    for(int i = n; i >= 1; i--)
    {
        auto it = s.upper_bound(a[i]);
        if(it == s.begin())
        {
            continue;
        }
        now++;
        suf[now] = i;
        s.erase(--it);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] >= suf[i])
        {
            break;
        }
        ans += suf[i] - pre[i];
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