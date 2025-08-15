#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<int, int> ma;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        cout << ma[a[i]] - 1 << " ";
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