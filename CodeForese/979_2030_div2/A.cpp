#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &z : v)
    {
        cin >> z;
    }
    sort(v.begin(), v.end());
    int max = v[n-1];
    int min = v[0];
    cout << max * (n - 1) - min * (n - 1) << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}