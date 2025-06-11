#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
    {
        int x = (i % 2 == 0 ? i / 2 : m - 1 - i / 2);
        int y = m - 1 - x;
        cout << a[x] << " " << a[y] << " " << a[x] << " " << a[y] << " " << a[x] << " " << a[y] << "\n";
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
