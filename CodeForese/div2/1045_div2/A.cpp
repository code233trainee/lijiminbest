#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    bool ok = false;
    if(a == b)
    {
        if(a % 2 == n % 2)
        {
            ok = true;
        }
    }
    else if(a < b)
    {
        if(n % 2 == b % 2)
        {
            ok = true;
        }
    }
    else if(b < a)
    {
        if(a % 2 == b % 2 && a % 2 == n % 2)
        {
            ok = true;
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
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