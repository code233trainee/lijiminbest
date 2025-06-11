#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    cout << 1 << " ";
    for(int i = n; i >= 2; i--)
    {
        cout << i << " \n"[i == 2];
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