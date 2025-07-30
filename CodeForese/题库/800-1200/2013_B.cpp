// https://codeforces.com/problemset/problem/2013/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << a[n] - (a[n-1] - (sum - a[n-1] - a[n])) << endl;
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