#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), [](auto &x, auto &y) -> bool {
        return x[0] < y[0];
    });
    sort(a.begin(), a.begin() + n / 2, [](auto &x, auto &y) -> bool {
        return x[1] < y[1];
    });
    sort(a.begin() + n / 2, a.end(), [](auto &x, auto &y) -> bool {
        return x[1] < y[1];
    });
    for(int i = 0; i < n / 2; i++)
    {
        cout << a[i][2] + 1 << " " << a[n-1-i][2] + 1 << endl;
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