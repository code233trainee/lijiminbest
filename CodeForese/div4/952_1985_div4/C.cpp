#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long sum = 0;
    int mx = 0; 
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        sum += v[i];
        mx = max(mx, v[i]);
        if((sum - mx) == mx)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}