#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<double> a(n+100);
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    a[++n] = sqrt((px - qx)*(px - qx) + (py - qy)*(py - qy));
    //注意溢出
    sort(a.begin() + 1, a.begin() + n + 1);
    double sum = a[n];
    for(ll i = 1; i < n; i++)
    {
        sum -= a[i];
    }
    if(sum <= 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}