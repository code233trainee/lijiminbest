#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, s;
    cin >> n >> s;
    int dxi, dyi, xi, yi;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> dxi >> dyi >> xi >> yi;
        if (dxi == dyi) // (-1, -1), (1, 1)
        {
            ans += (xi == yi);
        }
        else// (-1, 1), (1, -1)
        {
            ans += (xi + yi == s);
        } 
    }   
    cout << ans << endl;
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