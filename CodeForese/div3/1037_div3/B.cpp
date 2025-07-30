#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int res = 0;
        while(a[i] == 0 && i < n)
        {
            res++;
            if(res == k)
            {
                ans++;
                i++;
                break;
            }
            else
            {
                i++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}