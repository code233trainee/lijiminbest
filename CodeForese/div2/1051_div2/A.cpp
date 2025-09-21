#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> pos(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int mx = -1;
    int mn = 1e9;
    for(int i = n; i >= 1; i--)
    {
        mx = max(mx, pos[i]);
        mn = min(mn, pos[i]);
        if(mx - mn != n - i)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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