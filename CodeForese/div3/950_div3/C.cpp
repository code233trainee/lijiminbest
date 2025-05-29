#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cin >> m;
    vector<int> d(m);
    for(int i = 0; i < m; i++)
    {
        cin >> d[i];
    }

    int ans = 1;
    if(find(b.begin(), b.end(), d[m-1]) == b.end())
    {
        //d[m-1]最后一次需要赋值的值
        //如果没找到这个元素
        ans = 0;
    }
    //允许重复且自动升序排列
    multiset<int> s(d.begin(), d.end());
    for(int i = 0; i < n; i++)
    {
        if(b[i] != a[i])
        {
            if(!s.count(b[i]))
            {
                ans = 0;
            }
            //移除一个b[i]
            s.extract(b[i]);
        }
    }
    if(ans)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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