#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, k;
    cin >> n >> k;
    if(k != 0)
    {
        cout << (n/k - n/(k+1)) << endl;
    }
    else
    {
        cout << 1 << endl;
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
}