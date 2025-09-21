#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int k, x;
    cin >> k >> x;
    for(int i = 1; i <= k; i++)
    {
        x *= 2;
    }
    cout << x << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}