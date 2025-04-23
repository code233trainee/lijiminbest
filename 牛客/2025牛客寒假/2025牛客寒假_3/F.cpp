#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if(a+b+c >= n && a+b+c <= 2*n)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}