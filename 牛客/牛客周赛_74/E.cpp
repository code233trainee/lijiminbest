#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(a);
    //检查重复元素
    map<int, int> mp;
    for(int i = 1; i <= n; i++)
    {
        if(mp[a[i]])
        {
            cout << "NO\n";
            return;
        }
        mp[a[i]]++;
    }
    sort(b.begin() + 1, b.end());
    //对排序后的数字把a_i 映射为 a_{i + 1}
    map<int, int> to;
    for(int i = 1; i + m - 1 <= n; i++)
    {
        to[b[i]] = b[i + m -1];
    }
    // 单调递增->
    vector<int> pre(n + 5);
    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (a[i] > a[i - 1]);
    }
    for(int i = 1; i + m - 1 <= n; i++)
    {
        //满足单调
        if(pre[i+m-1] - pre[i] == m - 1)
        {
            if(to[a[i]] == a[i+m-1])
            {
                cout << "YES\n";
                return;
            }
        }
    }
    vector<int> suf(n+5);
    for(int i = n; i >= 1; i--)
    {
        suf[i] = suf[i+1] + (a[i] > a[i+1]);
    }
    for(int i = 1; i + m - 1 <= n; i++)
    {
        if(suf[i] - suf[i+m-1] == m - 1)
        {
            if(to[a[i+m-1]] == a[i])
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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