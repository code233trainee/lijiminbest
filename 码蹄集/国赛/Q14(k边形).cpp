//https://www.matiji.net/exam/brushquestion/53/4693/305EE97B0D5E361DE6A28CD18C929AF0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<ll> sub(n+1);
    for(ll i = 1; i <= n; i++)
    {
        sub[i] = a[i] + sub[i-1];
    }
    for(ll i = 1; i <= n - k + 1; i++)
    {
        if(sub[i + k - 2] - sub[i - 1] > a[i + k - 1])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}