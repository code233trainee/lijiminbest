#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int la = 0, lb = 0;
    while(la < n && lb < m)
    {
        if(a[la] == b[lb])
        {
            la++;
            lb++;
        }
        else
        {
            lb++;
        }
    }
    cout << la << endl;
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