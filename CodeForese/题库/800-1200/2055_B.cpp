// https://codeforces.com/problemset/problem/2055/B
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int bigger = INT_MAX, small = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= b[i])
        {
            bigger = min(bigger, a[i] - b[i]);
        }
        else if(a[i] < b[i])
        {
            small += b[i] - a[i];
            cnt++;
        }
    }
    
    if(cnt > 1)
    {
        cout << "NO\n";
    }
    else
    {
        if(cnt == 1)
        {
            if(bigger == INT_MAX)
            {
                cout << "NO\n";
                return;
            }
            if(bigger >= small)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "YES\n";
        }
    }
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