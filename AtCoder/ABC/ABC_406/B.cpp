#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    ll mx = pow(10, k);
    mx--;
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if(ans > (mx/x))
        {
            ans = 1;
        }
        else
        {
            ans *= x;
        }
    }
    cout << ans << endl;
    return 0;
}