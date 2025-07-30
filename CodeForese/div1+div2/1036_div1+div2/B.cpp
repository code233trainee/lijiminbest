#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << min(a[0], a[1]) + a[0] << endl;
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