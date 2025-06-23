#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s = "";
    for(int i = 1; i <= k; i++)
    {
        s += '1';
    }
    for(int i = 1; i <= n - k; i++)
    {
        s += '0';
    }
    cout << s << endl;
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