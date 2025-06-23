#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = abs(x - k);
    }
    sort(a.begin(), a.end());
    cout << a[m-1] << endl;
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