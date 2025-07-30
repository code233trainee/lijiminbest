// https://codeforces.com/problemset/problem/2057/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> ma;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ma[x]++;
        s.insert(x);
    }
    int ans = s.size();
    multiset<int> cnt;
    for(auto &z : s)
    {
        cnt.insert(ma[z]);
    }
    for(auto &z : cnt)
    {
        if(z <= k)
        {
            k -= z;
            ans--;
        }
    }
    ans = max(1, ans);
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