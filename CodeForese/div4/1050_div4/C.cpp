#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int now = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll len = a[i] - a[i-1];
        int need = (now != b[i]);
        ll add = ( (len % 2 == need) ? len : (len - 1) );
        ans += add;
        now = b[i];
    }   

    ans += m - a[n];
    
    cout << ans << endl;
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