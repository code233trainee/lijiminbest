#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int a[MAXN];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        if(2 * min(a[i], a[i + 1]) > max(a[i], a[i + 1]))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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