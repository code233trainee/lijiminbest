#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++)
    {
        cin  >> b[i];
    }
    int ans = a[n-1];
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] > b[i+1])
        {
            ans += a[i] - b[i+1];
        }
    }
    cout << ans << "\n";
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