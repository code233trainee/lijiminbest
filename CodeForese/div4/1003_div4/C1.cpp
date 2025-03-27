#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);//先把a中的第一个元素变的最小
    if(n <= 1)
    {
        cout << "YES\n";
        return;
    }
    for(ll i = 1; i < n; i++)
    {
        // lower_bound(start, end, value)
        // lower_bound在这里的用法：在已排序的数组 start 到 end 之间，找到 第一个 大于或等于 value 的元素的迭代器。
        // 如果找不到则会返回end的下一个迭代器，在这里也就是m
        int id = lower_bound(b.begin(), b.end(), a[i] + a[i-1]) - b.begin(); //这里是找出bj >= a[i-1] + a[i];
        //找到了对应的bj之后呢
        //如果id位置合法，并且我们可以使得ai在大于ai-1的前提下尽可能的更小，那么我们就改变
        //此题解法c1c2均适用
        if((id < m) && (a[i] < a[i-1] || b[id] - a[i] < a[i]))
        {
            a[i] = b[id] - a[i];
        }
    }
    for(ll i = 1; i < n; i++)
    {
        if(a[i] < a[i-1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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