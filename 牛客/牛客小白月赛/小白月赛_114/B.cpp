#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int num[1000010];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]] = 1;
    }
    sort(a.begin()+1, a.end());
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(num[i] == 1)
        {
            ans += i;
        }
    }
    cout << ans;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}