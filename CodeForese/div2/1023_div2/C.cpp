#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int pos = -1;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            pos = i;
            a[i] = -1e13;
        }
    }

    ll mx = 0;
    ll curr = 0;
    for(int i = 0; i < n; i++)
    {
        curr = max(curr + a[i], a[i]);
        mx = max(mx, curr);
    }
    if(mx > k || (mx != k && pos == -1))
    {
        cout << "NO\n";
        return;
    }
    if(pos != -1)
    {
        mx = 0;
        curr = 0;
        ll L, R;
        
        for(int i = pos + 1; i < n; i++)
        {
            curr += a[i];
            mx = max(mx, curr);
        }
        L = mx;
        mx = 0;
        curr = 0;
        for(int i = pos - 1; i >= 0; i--)
        {
            curr += a[i];
            mx = max(mx, curr);
        }
        R = mx;

        a[pos] = k - L - R;
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
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