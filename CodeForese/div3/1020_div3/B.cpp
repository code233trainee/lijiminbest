#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        ans[i] = i;   
    }
    if(n == 1)
    {
        cout << "0\n";
        return;
    }
    if(x == n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }
        return;    
    }
    swap(ans[n-1], ans[x]);
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
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