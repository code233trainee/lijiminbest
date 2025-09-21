#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
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
    ll cnt = 0;
    int mn = 3e5, mx = 0;
    for(int i = 1; i <= n; i++)
    {
        mn = min(mn, pos[i]);
        mx = max(mx, pos[i]);
        cnt += (ll)mn * (n - mx + 1);
    }
    cout << cnt << endl;
    return 0;
}