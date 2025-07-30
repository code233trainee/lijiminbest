#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    // 注意元素范围
    vector<int> a(n+2, 2e9);
    map<int, int> cnt, ma;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        ma[a[i]] = i;
    }
    int r = n;
    while(r >= 1 && a[r] < a[r+1] && a[r] >= r && cnt[a[r]] == 1)
    {
        r--;        
    }
    if(r == 0)
    {
        cout << 0 << endl;
        return;
    }
    set<int> s;
    for(int i = 1; i <= r; i++)
    {
        s.insert(a[i]);
    }
    int ans = s.size();
    for(auto z : s)
    {
        //如果有重复元素，set自动去重，而且必然会更改一次
        //所以我们只需要减去数量为一，并且元素等于下标的元素(这些是不用改的)
        if(cnt[z] == 1 && ma[z] == z)
        {
            ans--;
        }
    }
    cout << ans << endl;
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