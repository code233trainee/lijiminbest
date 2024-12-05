#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    int m = max(a, b);
    while(m % a != m % b)
    {
        m += 1;
    }
    cout << m << endl;
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