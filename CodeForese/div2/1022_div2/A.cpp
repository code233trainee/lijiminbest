#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    ll k = n / 2;
    if(n & 1)
    {
        cout << k * (k+1) + 1 << endl;
    }
    else
    {
        cout << k*k + 1 << endl;        
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