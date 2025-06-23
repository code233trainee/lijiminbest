#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int tot = a[n-1] - a[0];
    int mx = max(s - a[0], a[n-1] - s);
    if(s == a[0] || s == a[n-1])
    {
        cout << tot << endl;
        return;
    }
    if(s < a[0] || s > a[n-1])
    {
        if(s < a[0])
        {
            cout << tot + a[0] - s << endl;
        }
        else
        {
            cout << tot + s - a[n-1] << endl;
        }
        return;
    }
    cout << 2*tot - mx << endl;
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
