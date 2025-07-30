#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(a[n-1] <= a[0]*2)
    {
        cout << 2 << endl;
        return;
    }
    set<int> s;
    for(int i = 1; i < n - 1; i++)
    {
        s.insert(a[i]);
    }
    int last = a[n-1];
    int cnt = 2;
    while((last + 1) / 2 > a[0])
    {
        auto k = s.lower_bound((last + 1) / 2);
        if(k != s.end())
        {
            last = *k;
            cnt++;
            // 别忘了移除
            s.erase(k);
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << cnt << endl;
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