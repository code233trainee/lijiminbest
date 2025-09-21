#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int mx = -1, mn = 1e9+10;
    for(int i = 0; i < n; i++)
    {
        mx = max(a[i], mx);
        mn = min(a[i], mn);
        ans += mx + mn;
    }
    cout << ans << endl;
    return 0;
}