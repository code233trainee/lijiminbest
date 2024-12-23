#include <bits/stdc++.h>
using namespace std;
#define ll long long
// void solve()
// {
//     ll n, x, y;
//     cin >> n >> x >> y;
//     vector<ll> a(n+1);
//     ll total = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         total += a[i];
//     }
//     // vector<ll> b(n+2);
//     // for(int i = n; i >= 1; i++)
//     // {
        
//     // }
//     ll ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 1; j <= i; j++)
//         {
//             if(i != j)
//             {
//                 if(total - a[i] - a[j] >= x && total - a[i] - a[j] <= y)
//                 {
//                     ans++;        
//                 }
//             }
            
//         }
//     }
//     // for(int i = 1; i <= n; i++)
//     // {
//     //     for(int j = i+1; j <= n; j++)
//     //     {
//     //         if(total - a[i] - a[j] >= x && total - a[i] - a[j] <= y)
//     //         {
//     //             ans++;        
//     //         }
//     //     }
//     // }
//     cout << ans << "\n";
// }
void solve()
{
    ll n, X, Y;
    cin >> n >> X >> Y;
    vector<ll> A(n);
    for(auto &a : A)
    {
        cin >> a;
    }
    sort(A.begin(), A.end());
    ll A_sum = accumulate(A.begin(), A.end(), 0LL);
    ll PX = A_sum - Y;
    ll PY = A_sum - X;
    ll ans = 0;
    for(int i = 0, x = n, y = n; i < n; i++)
    {
        while(x > 0 && A[i] + A[x - 1] >= PX)
        {
            x--;
        }
        while(y > 0 && A[i] + A[y - 1] > PY)
        {
            y--;
        }
        ans += max(y, i + 1) - max(x, i + 1);
    }
    cout << ans << "\n";
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