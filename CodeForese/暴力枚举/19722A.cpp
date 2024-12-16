#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int l = n - 1;
    int r = l;
    int ans = 0;
    while(l >= 0)
    {
        if(a[l] > b[r])
        {
            l--;
            ans = max(ans, r - l);
        }
        else
        {
            l--;
            r--;
        }
    }
    cout << ans << "\n";
    //一发AC，如何呢？
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