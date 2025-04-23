#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    double n, x;
    cin >> n >> x;
    vector<tuple<double, double, double>> a(n);
    for(int i = 0; i < n; i++)
    {
        double x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
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