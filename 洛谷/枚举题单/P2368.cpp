#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
// 987654321

// 111111111
// 119357639
// 380642361
// 388888889
// 611111111
// 619357639
// 880642361
// 888888889
// n>9时只能以上述8个数结尾
// bool ok(ll i)
// {
//     if(i % 1000000000 == 987654321)
//     {
//         return true;
//     }
//     return false;
// }
int main()
{
    ll n = 9;
    cin >> n;
    if(n <= 8)
    {
        cout << 0 << endl;
        return 0;
    }
    // for(ll i = 100000000; i <= 999999999; i++)
    // {
    //     if(ok(i*i))
    //     {
    //         cout << i << endl;
    //     }
    // }
    if(n == 9)
    {
        cout << 8 << endl;
        return 0;
    }
    ll ans = 8;
    for(int i = 10; i <= n; i++)
    {
        if(i == 10)
        {
            ans *= 9;
            continue;
        }
        ans *= pow(10, n-10);
        break;
    }
    cout << ans << endl;
    return 0;
}