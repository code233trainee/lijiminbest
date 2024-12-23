#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m+1);
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    vector<int> q(m+1);
    for(int i = 1; i <= k; i++)
    {
        int k;
        cin >> k;
        q[k]++;
    }
    string ans = "";
    if( k < n-1)
    {
        ans = string(m, '0');
        cout << ans << "\n";
        return;
    }
    if(k == n)
    {
        ans = string(m, '1');
        cout << ans << "\n";
        return;
    }
    for(int i = 1; i <= m; i++)
    {
        if(q[a[i]] == 0)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
    }
    cout << ans << "\n";
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