#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;  i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            for(int k = j; k <= n; k++)
            {
                if(a[i] + a[j] == a[k])
                {
                    ans++;
                }
            }
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