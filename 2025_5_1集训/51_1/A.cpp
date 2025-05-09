// https://codeforces.com/problemset/problem/1903/A
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(k <= 1)
    {
        for(int i = 1; i < n; i++)
        {
            if(a[i] < a[i-1])
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
    else
    {
        cout << "YES\n";
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