#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int s;
    cin >> s;
    int k = 0;
    bool ok = true;
    int t = sqrt(s);
    if(s == t*t)
    {
        cout << 0 << " " << t << endl;
    }
    else
    {
        cout << -1 << endl;
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