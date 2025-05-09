#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    vector<int> pre(n+1), suf(n+2);
    int j = 1, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt < m && a[i] >= b[j])
        {
            j++;
            cnt++;
        }
        pre[i] = cnt;
        if(pre[i] == m)
        {
            cout << "0\n";
            return;
        }
    }
    j = m;
    cnt = 0;
    suf[n+1] = 0;
    for(int i = n; i >= 0; i--)
    {
        if(cnt < m && a[i] >= b[j])
        {
            j--;
            cnt++;
        }
        suf[i] = cnt;
    }
    int ans = INT_MAX;
    
    for(int i = 0; i <= n; i++)
    {
        if(pre[i] + suf[i+1] == m - 1)
        {
            ans = min(ans, b[pre[i] + 1]);
        }
    }
    if(ans == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
    // vector<int> pre(m+1, n+1), suf(m+1, -1);
    // pre[0] = 0;
    // for(int i = 0, j = 0; i < m; i++)
    // {
    //     while(j < n && a[j] < b[i])
    //     {
    //         j++;
    //     }
    //     if(j == n)
    //     {
    //         break;
    //     }
    //     pre[i+1] = ++j;
    // }
    // suf[m] = n;
    // for(int i = m - 1, j = n - 1; i >= 0; i--)
    // {
    //     while(j >= 0 && a[j] < b[i])
    //     {
    //         j--;
    //     }
    //     if(j < 0)
    //     {
    //         break;
    //     }
    //     suf[i] = j--;
    // }

    // int ans = 2e9;
    // for(int i = 0; i < m; i++)
    // {
    //     if(pre[i] <= suf[i+1])
    //     {
    //         ans = min(ans, b[i]);
    //     }
    // }
    // if(ans == INT_MAX)
    // {
    //     ans = -1;
    // }
    // cout << ans << endl;
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