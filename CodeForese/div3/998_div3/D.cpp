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
    for(int i = 2; i <= n; i++)
    {
        int t = min(a[i], a[i-1]);
        a[i] -= t;
        a[i-1] -= t;
    }
    for(int i = 1; i <= n-1; i++)
    {
        if(a[i] > a[i+1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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