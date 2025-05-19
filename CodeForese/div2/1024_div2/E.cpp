#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e6 + 5;

int a[maxn];
int pre[maxn], suf[maxn];
// pre[i]: 找到i个元素需要前几个数字
// suf[i]: 找到i个元素需要后几个数字
set<int> s;
int now = 0;
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
    // 每次可以erase一个<=自己的元素
    // 找到upper
    // 如果是begin 则continue
    // 否则 ans++, s.erase(--post);
    
    // 多测清空
    s.clear();
    for(int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    now = 0;
    for(int i = 1; i <= n; i++)
    {
        // 找到第一个大于a[i]的数字
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
    // 枚举选几个数字
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