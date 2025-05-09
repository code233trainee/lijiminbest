// https://codeforces.com/problemset/problem/1739/B
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    a[0] = b[0];
    for(int i = 1; i < n; i++)
    {
        a[i] = b[i] + a[i-1];
        if(b[i] == 0)
        {
            continue;
        }
        if(b[i] + a[i-1] >= 0 && a[i-1] - b[i] >= 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n-1];
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