#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> ma;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ma[x]++;
    }
    int ans = -1;
    for(auto &[x, y] : ma)
    {
        if(!ma.count(x-1))
        {
            ans++;
            if(!ma.count(x+1))
            {
                ans += y - 1;  
            }
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
    return 0;
}