// https://codeforces.com/problemset/problem/1857/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int mx = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, a[i] - b[i]);
    }
    int c = 0;
    for(int i = 1; i <= n; i++)
    {
        c += (a[i] - b[i] == mx);
    }
    cout << c << endl;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] - b[i] == mx)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
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