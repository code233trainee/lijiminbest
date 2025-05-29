#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, m, x;
    cin >> n >> m >> x;
    ll temp = 1 << (n - m + 1);  
    ll ans = temp - x + 1; 
    cout << ans << endl;
    return 0;
}