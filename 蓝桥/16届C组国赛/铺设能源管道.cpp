#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll x;
    cin >> x;
    // ll temp = x;
    // int tot = 0;
    // int cnt0 = 0, cnt1 = 0;
    // while(x)
    // {
    //     int k = x % 10;
    //     x /= 10;
    //     tot++;
    //     if(k == 1)
    //     {
    //         cnt1++;
    //     }
    //     else if(k == 0)
    //     {
    //         cnt0++;
    //     }
    // }   
    
    // if(cnt0 + cnt1 == tot)
    // {
    //     cout << temp << endl;
    // }
    // else
    // {
    //     ll ans = pow(10, tot);
    //     cout << ans << endl;
    // }
    ll ans = 1;
    while(ans < x)
    {
        ans *= 10;
    }
    cout << ans << endl;
    return 0;
}