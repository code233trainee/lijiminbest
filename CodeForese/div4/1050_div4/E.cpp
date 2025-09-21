#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> mx(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] % k != 0)
        {
            cout << 0 << endl;
            return;
        }
        mx[i] = cnt[i] / k;
    }

    ll ans = 0;
    int l = 1, r = 1;
    vector<int> use(n + 1, 0);
    for(; l <= n && r <= n; r++)
    {
        int val = a[r];
        use[val]++;
        while(use[val] > mx[val])
        {
            use[a[l]]--;
            l++;
        }
        ans += (ll)(r - l + 1);
    }
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