// https://codeforces.com/problemset/problem/1817/A
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> p(n-1);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n - 1; i++)
    {
        int down = a[i-1] >= a[i] && a[i] >= a[i+1];
        p[i] = p[i-1] + down;
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(l == r)
        {
            cout << "1\n";
        }
        else
        {
            int ans = r - l + 1 - p[r - 1] + p[l];
            cout << ans << endl;
        }
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}