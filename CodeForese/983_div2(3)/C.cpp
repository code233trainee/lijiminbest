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
    sort(v.begin(), v.end());
    
    int ans =  n - 2;
    int l = 0;
    for(int r = 2; r < n ; r++)
    {
        while( r - l >= 2 && v[l] + v[l+1] <= v[r])
        {
            l++;
        }
        ans = min(ans, n - (r - l + 1));
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