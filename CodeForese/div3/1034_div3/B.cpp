#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tar = a[j-1];
    sort(a.begin(), a.end(), greater<int>());
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        if(a[i] == tar)
        {
            break;
        }
    }
    int cnt = s.size();
    if(cnt > 1)
    {
        cnt = 2;
    }
    if(cnt <= k)
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