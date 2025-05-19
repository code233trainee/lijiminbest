#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> r(n), c(m);
    vector<int> pre(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    sort(r.begin(), r.end());
    for(int i = 0; i < n; i++)
    {
        pre[i+1] = pre[i] + r[i];
    }
    ll ans = 0;
    for(int i = 0; i < m; i++)
    {
        int index = lower_bound(r.begin(), r.end(), c[i]) - r.begin();  
        ans += (ll)index * c[i] + (pre[n] - pre[index]);
    }
    cout << ans << endl;
    return 0;
}