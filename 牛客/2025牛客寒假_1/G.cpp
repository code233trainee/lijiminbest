// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// void solve()
// {
//     ll n;
//     cin >> n;
//     ll low = 0, hig = 0;
//     vector<ll> a(n);
//     for(ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(), a.end());
//     for(int i = 0; i < n; i++)
//     {
//         if(a[i] >= i+1)
//         {
//             low += a[i] - i-1;
//         }
//         else
//         {
//             hig += i+1 - a[i];
//         }
//     }
//     if(low == hig)
//     {
//         cout << "1\n";
//     }
//     else
//     {
//         cout << "-1\n";
//     }
// }
// int main()
// {
//     solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(sum != (n*(n+1)) / 2)
    {
        cout << "-1\n";
        return 0;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += abs(a[i] - i - 1);
    }
    cout << ans/2 << "\n";
    return 0;
}