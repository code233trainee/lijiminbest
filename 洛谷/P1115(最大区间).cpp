#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> sum(n+1), min_pre(n+1);
    int mx = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > mx)
        {
            mx = a[i];
        }
        sum[i] = sum[i-1] + a[i];
        min_pre[i] = min(min_pre[i-1], sum[i]);
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, sum[i] - min_pre[i]);
    }
    if(mx < 0)
    {
        cout << mx << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}