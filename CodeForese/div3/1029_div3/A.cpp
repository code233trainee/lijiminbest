#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l, r;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1)
        {
            l = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] == 1)
        {
            r = i;
            break;
        }
    }
    if(x >= (r - l + 1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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